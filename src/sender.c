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

    // Send "OI" menssage.
    ret = oi_msg(sockfd, id);
    if (ret < 0) {
        return -1;
    }

    while(1) {
    }

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}
