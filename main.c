#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(void){
    struct addrinfo *addr;
    struct addrinfo hint;

    char hostIP[] = "www.google.com";

    memset(&hint, 0, sizeof(hint));

    hint.ai_family = AF_INET; // ipv4
    hint.ai_socktype = SOCK_STREAM; // tcp
    hint.ai_flags = AI_PASSIVE; // for bind() and connect()

    int status;
    if ((status = getaddrinfo(hostIP, NULL, &hint, &addr)) != 0){
        fprintf(stderr, "could't get addrinfo: %s", gai_strerror(status));
    }

    printf("Addresses found for %s: \n\n", hostIP);
    for (struct addrinfo *helper = addr; helper; helper = helper->ai_next){
        struct sockaddr_in *ip = (struct sockaddr_in *) helper->ai_addr;
        char addr_r[INET_ADDRSTRLEN];
        printf("%s", inet_ntop(helper->ai_family, &(ip->sin_addr), addr_r, sizeof(addr_r)));
    }


    freeaddrinfo(addr);
    return 0;
}
