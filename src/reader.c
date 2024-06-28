/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

/* System library */
#include <stdio.h>
#include <sys/socket.h>

/* Program library */
#include <handlesocket.h>
#include <server.h>
#include <client.h>
#include <msg.h>

/*============================================================================*
 * Main Function                                                              *
 *============================================================================*/

int main(int argc, char *argv[])
{
    // Verifys returns.
    int ret = 0;

    int port = 0;
    int id = 0;

    // Get cli args.
    ret = get_args(argc, argv, &port, &id);
    if (ret < 0) {
        return -1;
    }

    int sockfd = open_socket();
    if (sockfd < 0) {
        return -1;
    }

    fprintf(stdout, "Socket = %i \n", sockfd);

    ret = connect_server(sockfd, port);
    if (ret < 0) {
        return -1;
    }

    ret = handshake(sockfd, id);
    if (ret < 0) {
        return -1;
    } else {
        printf("===> Handshake Success \n");
    }

    while(1) {
        struct msg_t msg;
        msg.orig_uid = id;

        if (receive_message(sockfd, &msg) <= 0){
            fprintf(stderr, "\n ### ERROR: Failed to receive mensage.\n");
            return -1;
        }

        printf("User: %i\n", msg.orig_uid);
        printf("Message: %s \n", msg.text);

    }

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}

