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

        receive_message(sockfd, &msg);

        printf("Type: %i \n", msg.type);
        printf("Orig_uid: %i \n", msg.orig_uid);
        printf("Dest_uid: %i \n", msg.dest_uid);
        printf("Text_len: %i \n", msg.text_len);
        printf("Text: %s \n", msg.text);
    }

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}

