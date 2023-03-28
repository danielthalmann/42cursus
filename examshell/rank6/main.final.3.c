#include <errno.h>
#include <string.h>
#include <unistd.h>
#ifdef _WIN32
#include <winsock2.h>
#else
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#endif
#include <stdlib.h>
#include <stdio.h>


typedef struct s_client {
    int online;
    int id;
    char *buf;
} t_client;

t_client clients[1024];

void print(char *str)
{
	write(1, str, strlen(str));
}

void fatal()
{
    print("Fatal error\n");
    exit(1);
}

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				fatal();
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		fatal();
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int server_fd, connfd;
unsigned int len;
struct sockaddr_in servaddr, cli; 
int nfds, nbclients;
fd_set fds, cfds;
char recev_buf[128];
int recev_len;

void send_all(int id, char* prefix, char* msg)
{
    char *buf = 0;

    buf = malloc(sizeof(char) * 256);
    sprintf(buf, prefix, id);
    if(msg)
        buf = str_join(buf, msg);

    for(int fd = 0; fd < nfds; fd++)
    {
        if(clients[fd].online && clients[fd].id != id)
        {
            send(fd, buf, strlen(buf), 0);
        }
    }
    free(buf);
}

int main(int argc, char** argv) {

    if(argc != 2)
    {
        print("Wrong number of arguments\n");
        exit(1);
    }

    // socket create and verification 
	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (server_fd == -1)
        fatal();

    bzero(&servaddr, sizeof(servaddr));
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
        fatal(); 

	if (listen(server_fd, 10) != 0)
        fatal();

    FD_SET(server_fd, &cfds);

    nfds = server_fd + 1;

    bzero(clients, sizeof(clients));

    nbclients = 0;

    while(1) 
    {

        fds = cfds;
        int n = select(nfds, &fds, NULL, NULL, NULL);
        if (n < 0)
            continue;
            // fatal();

        for(int fd = 0; fd < nfds; fd++)
        {
            if(FD_ISSET(fd, &fds))
            {

                if (fd == server_fd)
                {
                    len = sizeof(cli);
                    connfd = accept(server_fd, (struct sockaddr *)&cli, &len);
                    if (connfd > -1) { 

// printf("connect %d\n", connfd);

                        clients[connfd].online = 1;
                        clients[connfd].id = nbclients++;
                        clients[connfd].buf = 0;
                        send_all(clients[connfd].id, "server: client %d just arrived\n", NULL);
                        FD_SET(connfd, &cfds);
                        if (!(connfd < nfds))
                            nfds = connfd + 1;
                    } 
                }
                else
                {
                    recev_len = recv(fd, &recev_buf, 127, 0);

                    if(recev_len < 1) {

                        send_all(clients[fd].id, "server: client %d just left\n", NULL);

                        clients[fd].online = 0;
                        clients[fd].id = 0;
                        free(clients[fd].buf);
                        FD_CLR(fd, &cfds);
                        close(fd);

                    } else {

                        recev_buf[recev_len] = 0;
                        clients[fd].buf = str_join(clients[fd].buf, recev_buf);
                        char *msg;

                        while(extract_message(&clients[fd].buf, &msg)) {
                            send_all(clients[fd].id, "client %d: ", msg);
                            free(msg);
                        }

                    }


                }

            }


        }

    }

        
}