#ifndef PING_H
#define PING_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdint.h>
#include <sys/time.h>
#include <errno.h>

typedef struct s_ping {
    double    timing_tab[7];
    int         ttl;

    int     sockfd;
    char* target;
    char ip[100];
    uint16_t seq;

    struct icmp  *icmp_header;
    struct sockaddr_in dest_addr;

    struct timeval lst;
}               t_ping;

#endif