#include <stdio.h>
#include <sys/socket.h>
#include <handsocket.h>
#include <msg.h>

int main() {

    char buffer[12];

    for (int i = 0; i < 12; i++){
        buffer[i] = 'a';
    }

    int ret = 0;

    int sockfd = open_socket();
    if (sockfd < 0) {
        return -1;
    }

    printf("Socket = %i \n", sockfd);

    ret = setaddr_socket(sockfd);
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

    while (1) {
        int csock = accept_connection(sockfd);
        if (ret < 0) {
            return -1;
        }

        send(csock, &buffer, 12, 0);
    }

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}
