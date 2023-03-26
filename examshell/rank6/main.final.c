#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

typedef struct client_s
{
	int fd;
	int id;
	char buf[512];
	struct client_s *next;
} client_t;

void print(char *str)
{
	write(1, str, strlen(str));
}

void fatal()
{
	print("Fatal error\n"); 
	exit(0); 
}

client_t *createClient(int fd, int id)
{

	client_t *client = calloc(sizeof(client_t), 1);
	if(!client)
		fatal();
	client->id = id;
	client->fd = fd;
	return client;
}

void addClient(client_t **root, client_t *client)
{

	client->next = *root;
	*root = client;
}

void removeClient(client_t **root, client_t *client)
{

	client_t *next;
	if (*root == client)
	{
		*root = client->next;
	} else {
		next = *root;
		while(next->next && next->next != client){
			next = next->next;
		}
		next->next = client->next;
	}
	free(client);
}

void sendall(client_t *client, char *msg, int id)
{
	print("sendall : \n");

	print(msg);

	while(client)
	{
		if(client->id != id) 
			send(client->fd, msg, strlen(msg), 0);

		client = client->next;
	}
}

void sendclientconnect(client_t *client, int id)
{
	char buff[128];
	sprintf(buff, "server: client %d just arrived\n", id);

	sendall(client, buff, id);
}

void sendclientleave(client_t *client, int id)
{
	char buff[128];
	sprintf(buff, "server: client %d just left\n", id);

	sendall(client, buff, id);
}

int main(int argc, char **argv) 
{
	int serverfd, connfd, nfds;
	unsigned int len;
	struct sockaddr_in servaddr, cli;
	client_t *client = 0;
	client_t *clients = 0;
	fd_set fds, cfds;
	int clientidx = 0;
	char buff[4096 * 42];
	char buff_send[4096 * 42];
	int ret;

	// verify input port
	if (argc != 2){
		print("Wrong number of arguments\n");
		return 1;
	}

	unsigned int port = atoi(argv[1]);

	// socket create and verification 
	serverfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (serverfd == -1) 
		fatal();

	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port);

	FD_ZERO(&fds);
	FD_SET(serverfd, &fds);
	nfds = serverfd + 1;
  
	// Binding newly created socket to given IP and verification 
	if ((bind(serverfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal();
	
	if (listen(serverfd, 10) != 0) 
		fatal();

	while(1)
	{
		cfds = fds;

		ret = select(nfds, &cfds, NULL, NULL, NULL);

		if (ret == -1) 
			fatal();

		for(int fd = 0; fd < nfds; fd++)
		{
			if(FD_ISSET(fd, &cfds))
			{
				if (fd == serverfd)
				{
					len = sizeof(cli);
					connfd = accept(serverfd, (struct sockaddr *)&cli, &len);
					if (connfd < 0) 
						fatal();

					FD_SET(connfd, &fds);
					if (nfds <= connfd)
						nfds = connfd + 1;
					
					client_t *c = createClient(connfd, clientidx++);
					addClient(&clients, c);
					sendclientconnect(clients, c->id);

				} else {

					client = clients;
					while(client)
					{
						client_t *leave = 0;

						if (client->fd == fd)
						{

							ret = recv(client->fd, buff, 511, 0);

							if (ret < 0)
								fatal();

							// close connexion
							if (ret == 0) {
								leave = client;
							} else {

								buff[ret] = 0;

								char *start = buff;

								printf("buff[ret: %d] : %s", ret, buff);
								for(int i = 0; i < ret; i++)
								{
									print("[");
									write(1, &buff[i], 1);
									print("]");
									if (buff[i] == '\n')
									{
										if (buff[i] == '\n')
											buff[i] = 0;

										sprintf(buff_send, "client %d: %s\n", client->id, start);
										sendall(clients, buff_send, client->id);
										i++;
										start = buff + i;
									}
								}
							
							}

						}

						client = client->next;

						if(leave)
						{
							FD_CLR(leave->fd, &fds);
							sendclientleave(clients, leave->id);
							close(leave->fd);
							removeClient(&clients, leave);
						}
					}

				}

			}
		
		}

	}

}