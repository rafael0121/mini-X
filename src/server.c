#include <stdio.h>
#include <sys/socket.h>
#include <handsocket.h>
#include <server.h>
#include <msg.h>

int main() {

    int ret = 0;

    int sockfd = open_socket();
    if (sockfd < 0) {
        return -1;
    }

    printf("Socket = %i \n", sockfd);

    ret = setaddr_socket(sockfd, SERVER_PORT);
    if (ret < 0) {
        return -1;
    }

    ret = settimeout_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    ret = listen_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    ret = accept_connection(sockfd);
    if (ret < 0) {
        return -1;
    }

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}
