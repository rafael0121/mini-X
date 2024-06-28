/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

/* System library */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

/* Program library */
#include <handlesocket.h>
#include <server.h>
#include <client.h>
#include <msg.h>

/*============================================================================*
 * Private Function                                                           *
 *============================================================================*/

int menu(struct msg_t *msg) {
    int dest;
    char *text = NULL;

    printf("\n==============\n");
    printf("Type destiny id (0(all) - 999): ");
    scanf("%i", &dest);
    printf("\n");

    if (dest < 0 || dest > 999) {
        return -1;
    }

    printf("Type the menssage (max 140 char): ");
    scanf("%ms", &text);

    int length = strlen(text);

    if(length > 140) {
        return -1;
    }

    msg->type = MSG;
    msg->dest_uid = dest;
    msg->text_len = length;
    strcpy((char *) msg->text, text);

    return 0;
}

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

        ret = menu(&msg);
        if (ret < 0) {
            return -1;
        }

        send_msg(sockfd, msg);
    }

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}
