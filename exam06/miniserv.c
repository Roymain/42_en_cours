#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>

int sockfd;
size_t id_max = 0;
fd_set	pool_set;
fd_set	write_set;
fd_set	read_set;

typedef struct list {
	int fd;
	int	id;
	int	new;
	struct list *next;
} t_list;

t_list	*list;


void	fatal() {
	char	str[] = "Fatal error\n";
	write(2, str, strlen(str));
	exit(1);
}

void	fatal_args() {
	char	str[] ="Wrong number of arguments\n";
	write(2, str, strlen(str));
	exit(1);
}



int max_fd(){
	int fdmax = 0;
	for (t_list *tmp = list; list ; tmp = tmp->next){
		if (tmp->fd > fdmax)
			fdmax = tmp->fd;
	}
	if (fdmax == 0)
		return sockfd;
	return fdmax;
}

void		send_all(char *str, ssize_t len, int fd_sender) {
	for (t_list *tmp = list ; tmp ; tmp = tmp->next) {
		if (FD_ISSET(tmp->fd, &write_set) && tmp->fd != fd_sender)
			if (send(tmp->fd, str, len, 0) < 0)
				fatal();
	}
}

void	add_list(t_list *new_cli) {
	if (list == NULL) {
		list = new_cli;
		return ;
	}
	for (t_list *tmp = list ; tmp ; tmp = tmp->next) {
		if (tmp->next == NULL) {
			tmp->next = new_cli;
			break;
		}
	}
}

void add_client(){
	char header[100];
	struct sockaddr_in 	cli;
	socklen_t len = sizeof(cli);
	t_list *newcli = calloc(1, sizeof(t_list));

	bzero(&cli, sizeof(cli));
	bzero(header, 100);




	newcli->fd = accept(sockfd, (struct sockaddr *)&cli, &len);

	newcli->id = id_max;
	id_max++;
	newcli->next = NULL;
	newcli->new = 1;

	FD_SET(newcli->fd, &pool_set);
	// add lst
	sprintf(header, "server: client %d just arrived\n", newcli->id);
	send_all(header, strlen(header), newcli->fd);
}

int main(int argc, char **argv){
	struct sockaddr_in servaddr;   //struct to handle internet add
	uint16_t port;
	sockfd = 0;

	if (argc != 2)
		return (write(2, "error\n", 7));
	else
		port = atoi(argv[1]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);  // ?? comment connaitre cette val
	servaddr.sin_port = htons(port);
	FD_ZERO(&pool_set);
	FD_ZERO(&write_set);
	FD_ZERO(&read_set);
	FD_SET(sockfd, &pool_set);

	// // Binding newly created socket to given IP and verification 
	// if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
	// 	fatal();	
	// if (listen(sockfd, 100000) != 0) 
	// 	fatal();

	while (1){
		int nbrfd = max_fd();
		FD_COPY(&pool_set, &read_set);
		FD_COPY(&pool_set, &write_set);
		if (select(nbrfd + 1, &read_set, &write_set, NULL, 0) < 0) {
			continue ;
		}
		for (int i = 0; i < nbrfd + 1; i++){
			if (FD_ISSET(i, &read_set)){
				if (i == sockfd){
					//ft add clit
					break;
				}
				else
					if (msg(i))
			}
		}
	}

	return (0);
}