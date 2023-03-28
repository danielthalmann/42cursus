#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

// 21:55

typedef struct s_client {
    int id;
    int online;
    char *buf;
} t_c;

void print_err(char *s)
{
    write(2, s, strlen(s));
}

void fatal()
{
    print_err("Fatal error\n");
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

int server_fd, client_fd;
unsigned int len;
struct sockaddr_in servaddr, cli;
// nombre de client maximum simultané 1024
t_c clients[1024];
int nfds;
fd_set fds, allfds;
int ids;
int ret;
char read_buf[251];

void send_all(char* prefix, int id, char* msg)
{
    char* buf = malloc(100);
    if (!buf)
        fatal();
    sprintf(buf, prefix, id);
    if (msg)
        buf = str_join(buf, msg);
    for (int fd = 0; fd < nfds; fd++)
    {
        if (clients[fd].online && id != clients[fd].id)
            send(fd, buf, strlen(buf), 0);
    }
    free(buf);
}

int main(int argc, char** argv) {

    if (argc != 2)
    {
        print_err("Wrong number of arguments\n");
        return 1;
    }

    bzero(clients, sizeof(clients));

    int port = atoi(argv[1]);

    //printf("port : %d, %d, %d\n",  ((port & 0x00FF) << 8) | ((port & 0xFF00) >> 8), htons(port), port);
    //printf("adresse : %d, %d, %d\n",  (1 << 24) + 127,htonl(2130706433), 2130706433);

	
	// socket create and verification 
	server_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (server_fd == -1) { 
		fatal(); 
	} 

	bzero(&servaddr, sizeof(servaddr)); 
	bzero(&allfds, sizeof(allfds)); 
    FD_ZERO(&allfds);
    FD_SET(server_fd, &allfds);
    nfds = server_fd + 1;
    ids = 0;

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = (1 << 24) + 127; //  htonl(2130706433); //127.0.0.1
	servaddr.sin_port = ((port & 0x00FF) << 8) | ((port & 0xFF00) >> 8); // htons(8081);
  
	// Binding newly created socket to given IP and verification 
	if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
        fatal();
	} 
	if (listen(server_fd, 10) != 0) {
		fatal();
	}

    while (1)
    {

        fds = allfds;

        printf("start select %d\n", nfds);
        
        ret = select(nfds, &fds, NULL, NULL, NULL);

        if (ret < 1)
            continue;

        for (int fd = 0; fd < nfds; fd++)
        {
            if (FD_ISSET(fd, &fds))
            {
                if (fd == server_fd)
                {
                    len = sizeof(cli);
                    client_fd = accept(server_fd, (struct sockaddr *)&cli, &len);
                    
                    if (client_fd > -1) { 
                     
                        clients[client_fd].id = ids++;
                        clients[client_fd].online = 1;
                        clients[client_fd].buf = 0;

                        send_all("server: client %d just arrived\n", clients[client_fd].id, NULL);

                        FD_SET(client_fd, &allfds);

                        if (! (client_fd < nfds))
                            nfds = client_fd + 1;
                    }

                } else {

                    ret = recv(fd, read_buf, 2, 0);

                    // déconnexion ou erreur
                    if (ret < 1)
                    {
                        free(clients[fd].buf);
                        clients[fd].online = 0;
                        send_all("server: client %d just left\n", clients[fd].id, NULL);
                        clients[fd].id = 0;
                        FD_CLR(fd, &allfds);
                        close(fd);


                    } else {

                        read_buf[ret] = 0;

                        clients[fd].buf = str_join(clients[fd].buf, read_buf);
                        char *msg = 0;
                        while(extract_message(&clients[fd].buf, &msg))
                        {
                            send_all("client %d: ", clients[fd].id, msg);
                            free(msg);
                        }

                    }

                }

            }
        }
        

    }
    

}