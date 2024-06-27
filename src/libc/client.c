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

    socklen_t lenght = sizeof(addr);
    
    int ret = connect(sockfd, (struct sockaddr *) &addr, lenght);

    if (ret < 0) {
        printf("\n ### ERROR: Failed to connect with the server. errno: %i \n", errno);
    } else {
        printf("\n Succesfull connect \n");
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
        printf("\n ### ERROR: Missing Arguments.\n");
        HELPCLIENT(argv[0]);
        return -1;
    }

    // Get port and check if is valid.
    *port = atoi(argv[1]);
    if (*port < 1024 || *port > 65536) {
        printf("\n ### ERROR: PORT is out of limit.\n");
        HELPCLIENT(argv[0]);
        return -1;
    }

    // Get id and check if is valid.
    *id = atoi(argv[2]);
    if (*id < 1) {
        printf("\n ### ERROR: ID must be greater than 0.\n");
        HELPCLIENT(argv[0]);
        return -1;
    }

    return 0;
}
