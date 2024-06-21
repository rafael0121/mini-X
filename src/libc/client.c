/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <server.h>

/*============================================================================*
 * Public Functions                                                          *
 *============================================================================*/

/**
 * @brief Connect to the server.
 *
 * @return Upon succesfull zero is returned. otherwise
 * a negative errno.
 */
int connect_server(int sockfd)
{
    // Server address.
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = SERVER_PORT;
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
