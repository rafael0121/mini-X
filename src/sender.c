/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

#include <stdio.h>
#include <sys/socket.h>
#include <handlesocket.h>
#include <server.h>
#include <client.h>
#include <msg.h>

/*============================================================================*
 * Main Function                                                              *
 *============================================================================*/

int main()
{
    int ret = 0;

    int sockfd = open_socket();
    if (sockfd < 0) {
        return -1;
    }

    printf("Socket = %i \n", sockfd);

    ret = connect_server(sockfd);
    if (ret < 0) {
        return -1;
    }

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}
