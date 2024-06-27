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

    struct msg_t msg;
    msg.type = OI;
    msg.orig_uid = id;
    msg.dest_uid = 0;
    msg.text_len = 1;
    msg.text[0] = 'a';

    printf("\n\n %i", msg.type);

    send_msg(sockfd, msg);

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}
