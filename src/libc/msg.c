/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <msg.h>

/*============================================================================*
 * Public Functions                                                          *
 *============================================================================*/

int receive_message(int sockfd, struct msg_t *msg)
{
    size_t length = sizeof(*msg);

    // Read the arrived data.
    int ret = read(sockfd, msg, length);

    if (ret < 0) {
        printf("\n ### ERROR: Failed to receive menssage. errno: %i \n", errno);
        return -1;
    }

    if (ret == 0) {
        printf("\n ### ERROR: No data read from socket: %i \n", sockfd);
        return 0;
    }

    return ret;
}

int send_msg(int dest_sock, struct msg_t msg) {

    size_t length = sizeof(msg);

    int ret = write(dest_sock, &msg, length);
    if (ret < 0) {
        printf("\n ### ERROR: Failed to send %i message. errno: %i \n",msg.type, errno);
        return -1;
    }

    if (ret == 0) {
        printf("\n ### ERROR: No data sended from socket: %i.\n", dest_sock);
        return -2;
    }

    return ret;
}
