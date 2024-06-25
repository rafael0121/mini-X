/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

/* System library */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/* Program library */
#include <handlesocket.h>

/*============================================================================*
 * Public Functions                                                          *
 *============================================================================*/

/**
 * @brief Open socket using default values.
 *
 * @return Upon succesfull socket address is returned, otherwise
 * a negative errno.
 */
int open_socket()
{
    // Open socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("\n ### ERROR: Failed to create socket. errno: %i \n", errno);
    }

    return sockfd;
}

/**
 * @brief Close a socket.
 *
 * @return Upon succesfull zero is returned, otherwise
 * a negative errno.
 */
int close_socket (int sockfd)
{
    int ret = close(sockfd);

    if (ret < 0) {
        printf("\n ### ERROR: Failed to close socket. errno: %i \n", errno);
    }

    return ret;
}
