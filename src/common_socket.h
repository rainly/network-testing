/* -*- c-file-style: "linux" -*-
 * Author: Jesper Dangaard Brouer <netoptimizer@brouer.com>, (C)2014
 * License: GPLv2
 * From: https://github.com/netoptimizer/network-testing
 *
 * Common socket related helper functions
 */
#ifndef COMMON_SOCKET_H
#define COMMON_SOCKET_H

#include <stdint.h> /* types uintXX_t */
#include <netinet/in.h> /* sockaddr_in{,6} */

/* Wrapper functions with error handling like "Stevens" */
int Socket(int addr_family, int type, int protocol);
int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int Setsockopt (int fd, int level, int optname, const void *optval,
		socklen_t optlen);

/* Helpers */
void setup_sockaddr(int addr_family, struct sockaddr_storage *addr,
		    char *ip_string, uint16_t port);

socklen_t sockaddr_len(const struct sockaddr_storage *sockaddr);

#endif /* COMMON_SOCKET_H */
