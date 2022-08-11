
// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>

#include "0_headers/test_server/testing.h"

#define PORT 3000
#define MAXLINE 255 + 2 + 2

// Driver code
int main()
{
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;
    socklen_t servlen = sizeof(servaddr);

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n, len;

    Testing t(43008, 43008, "This is a message", 100);

    // std::cout << t.getmessage() << std::endl;

    for (int i = 0; i < 20; i++)
    {
        // std::cout << i << " messages have been sent" << std::endl;
        t.generate_message(buffer, t.getAckNum() + (256 * i), t.getSeqNum() + (256 * i));
        // std::cout << buffer << std::endl;
        sendto(sockfd, (char *)buffer, MAXLINE,
               MSG_CONFIRM, (const struct sockaddr *)&servaddr,
               sizeof(servaddr));
    }

    // n = recvfrom(sockfd, (char *)buffer, MAXLINE,
    //              MSG_WAITALL, (struct sockaddr *)&servaddr,
    //              &servlen);
    // buffer[n] = '\0';
    // printf("Server : %s\n", buffer);

    close(sockfd);
    return 0;
}