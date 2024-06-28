/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

/* System library */
#include <stdio.h>
#include <stdlib.h>
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
    char input[4];
    char ch[4];
    char text[140];

    printf("\n==============\n");
    printf("Send a message (1)\n");
    printf("Exit (0)\n");
    if (fgets(ch, 4, stdin) == NULL) {
        return -1;
    }

    if (atoi(ch) == 0) {
        return -1;
    }

    printf("Type destiny id (0(all) - 999): ");
    if (fgets(input, 4, stdin) == NULL) {
        return -1;
    }
    printf("\n");

    int dest = atoi(input);

    if (dest < 0 || dest > 999) {
        return -1;
    }

    printf("Type the message (max 140 char): ");
    getchar();
    if (fgets(text, 140, stdin) == NULL) {
        return -1;
    }

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

    fprintf(stdout, "Socket = %i \n", sockfd);

    ret = connect_server(sockfd, port);
    if (ret < 0) {
        return -1;
    }

    ret = handshake(sockfd, id);
    if (ret < 0) {
        fprintf(stderr, "\n ### ERROR: Handshake Failed\n");
        return -1;
    } else {
        fprintf(stdout, "===> Handshake Success \n");
    }

    while(1) {
        struct msg_t msg;
        msg.orig_uid = id;

        ret = menu(&msg);
        if (ret < 0) {
            break;
        }

        if (send_message(sockfd, msg) < 0){
            fprintf(stderr, "\n ### ERROR: Failed to send mensage.\n");
        }
    }

    // TCHAU Struct
    struct msg_t msg;
    msg.type = TCHAU;
    msg.orig_uid = id;
    msg.dest_uid = 0;

    send_message(sockfd, msg);

    ret = close_socket(sockfd);
    if (ret < 0) {
        return -1;
    }

    return 0;
}
