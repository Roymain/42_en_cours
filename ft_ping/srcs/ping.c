#include "../includes/ping.h"

uint16_t checksum(uint16_t *addr, int len) {
    int nleft = len;
    uint16_t *w = addr;
    uint16_t answer;
    int sum = 0;

    // Additionne 16 bits jusqu'à ce qu'il ne reste plus que des octets isolés
    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }

    // Ajoute l'octet isolé restant si présent
    if (nleft == 1) {
        *(uint8_t *)(&answer) = *(uint8_t *)w;
        sum += answer;
    }

    // Ajoute les bits de report et répète l'opération jusqu'à ce que le bit de report soit nul
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    // Complémente à un le résultat
    answer = ~sum;

    return answer;
}

int host_to_ip(t_ping *ping) {

    char host[100];
    struct addrinfo hint;
    struct addrinfo *servinfo, *tmp;

    bzero(&hint, sizeof(hint));

    hint.ai_family = AF_INET;   
 
    if (getaddrinfo(ping->target, NULL, &hint, &servinfo) < 0) {
      fprintf(stderr, "ft_ping: error getaddrinfo  => %s\n", ping->target);
      return 0;
    } else if (servinfo == NULL) {
      fprintf(stderr, "ft_ping: cannot resolve: %s: Unknown host\n",
              ping->target);
      return 0;
    }

    for (tmp = servinfo; tmp != NULL; tmp = tmp->ai_next) {
      getnameinfo(tmp->ai_addr, tmp->ai_addrlen, host, sizeof(host), NULL, 0,
                  NI_NUMERICHOST);
      strcpy(ping->ip, host);
    }

    freeaddrinfo(servinfo);

    return 1;
}


int main(int argc, char** argv){

	int sockfd;

	sockfd = 0;

	t_ping *ping = malloc(sizeof(t_ping));
	if (ping == NULL)
		return 0;
	bzero(ping, sizeof(t_ping));
 
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
	if (sockfd == -1)
		exit(fprintf(stderr, "failed sockfd\n"));
	ping->target = argv[1];
	host_to_ip(ping);
	ping->ttl = 64;
	ping->seq = 1;
// HEADER IP
	struct iphdr ip_header;
	memset(&ip_header, 0, sizeof(ip_header));

    ip_header.ihl = 5;
    ip_header.version = 4;
    ip_header.ttl = 64;
    ip_header.protocol = IPPROTO_ICMP;
    ip_header.daddr = inet_addr(ping->ip);
    ip_header.id = htons(getpid() & 0xFFFF);
    ip_header.tot_len = sizeof(struct iphdr) + sizeof(struct icmphdr);
	ping->ip_header = &ip_header;

// HEADER ICMP
	struct icmp icmp_header;
	memset(&icmp_header, 0, sizeof(icmp_header));

    icmp_header.icmp_type = ICMP_ECHO;
    icmp_header.icmp_code = 0;
	icmp_header.icmp_id = getpid() & 0xFFFF;
	icmp_header.icmp_seq = htons(ping->seq);
	icmp_header.icmp_cksum = 0;
    icmp_header.icmp_cksum = checksum((uint16_t *)&icmp_header, sizeof(icmp_header));
	ping->icmp_header = &icmp_header;

fprintf(stderr, "%s\n", ping->target);

	ping->dest_addr.sin_family = AF_INET;
	ping->dest_addr.sin_addr.s_addr = inet_addr(ping->ip);
//envoie du paquet
    
	struct timeval timeout;
	timeout = (struct timeval){10, 0};   //10s
	char buf[1024];
	struct sockaddr_in from;
	socklen_t fromlen = sizeof(from);
	bzero(buf, 1024);
	int ret = 0;
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
	    perror("setsockopt failed\n");
	    exit(1);
	}
 	if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ping->ttl, sizeof(ping->ttl)) == -1) {
    	fprintf(stderr, "ft_ping: error set setsockopt ttl: %s\n", strerror(errno));
    	return EXIT_FAILURE;
  	}
	struct timeval end_time;
	
	gettimeofday(&ping->lst, NULL);

	sendto(sockfd, ping->icmp_header, sizeof(ping->icmp_header), 0, (struct sockaddr*)&ping->dest_addr, sizeof(ping->dest_addr));

	ret = recvfrom(sockfd, &buf, sizeof(buf), 0, (struct sockaddr*)&from, &fromlen);
	if (ret < 0) {
	    printf("Timeout\n");
	} else {
	    printf("Reply from %s\n", inet_ntoa(from.sin_addr));
	}
	
//TODO timne to live

	gettimeofday(&end_time, NULL);
	double rtt = (end_time.tv_sec - ping->lst.tv_sec) * 1000.0;
	rtt += (end_time.tv_usec - ping->lst.tv_usec) / 1000.0;
	printf("%d bytes received from %s (%s), seq: %d ; tt = %d ; Ping response time: %f ms\n", ret, ping->target, ping->ip, ping->seq, ping->ttl, rtt);
}