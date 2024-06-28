/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

/* System library */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

/* Program librarys */
#include <server.h>
#include <client.h>
#include <msg.h>

/*============================================================================*
 * Public Functions                                                          *
 *============================================================================*/

/**
 * @brief Connect to the server.
 *
 * @return Upon succesfull zero is returned. otherwise
 * a negative errno.
 */
int connect_server(int sockfd, int port)
{
    // Server address.
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = port;
    addr.sin_addr.s_addr = INADDR_ANY;

    socklen_t length = sizeof(addr);
    
    int ret = connect(sockfd, (struct sockaddr *) &addr, length);

    if (ret < 0) {
        fprintf(stderr, "\n ### ERROR: Failed to connect with the server. errno: %i \n", errno);
    } else {
        fprintf(stdout, "\n Succesfull connect \n");
    }

    return ret;
}

/**
 * @brief Get value from cli arguments.
 *
 * @return Upon succesfull zero is returned. otherwise
 * a negative error.
 */
int get_args(int argc, char *argv[], int *port, int *id)
{
    // Check numbers of args.
    if (argc != 3) {
        fprintf(stderr, "\n ### ERROR: Missing Arguments.\n");
        HELPCLIENT(argv[0]);
        return -1;
    }

    // Get port and check if is valid.
    *port = atoi(argv[1]);
    if (*port < 1024 || *port > 65536) {
        fprintf(stderr, "\n ### ERROR: PORT is out of limit.\n");
        HELPCLIENT(argv[0]);
        return -1;
    }

    // Get id and check if is valid.
    *id = atoi(argv[2]);
    if (*id < 1) {
        fprintf(stderr, "\n ### ERROR: ID must be greater than 0.\n");
        HELPCLIENT(argv[0]);
        return -1;
    }

    return 0;
}

/**
 * @brief Register client in server.
 *
 * @return Upon succesfull zero is returned. otherwise
 * a negative error.
 */
int handshake (int sockfd, int id) {
    struct msg_t msg;

    msg.type = OI;
    msg.orig_uid = id;
    msg.dest_uid = 0;
    msg.text_len = 0;
    msg.text[0] = '\0';

    int ret = send_message(sockfd, msg);
    if (ret <= 0) {
        fprintf(stderr, "\n ### ERROR: [HANDSHAKE] Failed to send mensage.\n");
        return -1;
    }

    struct msg_t rec_msg;

    ret = receive_message(sockfd, &rec_msg);
    if (ret < 0) {
        fprintf(stderr, "\n ### ERROR: [HANDSHAKE] Failed to receive mensage.\n");
        return -1;
    }

    if (rec_msg.orig_uid == msg.dest_uid) {
        return 0;
    }

    return -1;
}
