/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <msg.h>

/*============================================================================*
 * Public Functions                                                          *
 *============================================================================*/

int receive_message(int sockfd, msg_t *msg)
{
    size_t lenght = sizeof(msg);

    // Read the arrived data.
    int ret = read(sockfd, &msg, lenght);

    if (ret < 0) {
        printf("\n ### ERROR: Failed to receive menssage from server. errno: %i \n", errno);
        return -1;
    }

    return 0;
}

int oi_msg(int server_sock, int programid, int client) {

    msg_t msg;

    msg.type = OI;
    msg.orig_uid = programid;
    msg.dest_uid = SERVER; 
    msg.text_len = 
    msg.text = client + '0'.

    size_t lenght = sizeof(msg);

    int ret = write(server_sock, &msg, lenght);
    if (ret < 0) {
        printf("\n ### ERROR: Failed to send OI message. errno: %i \n", errno);
        return -1;
    }

    return 0;
}


int tchau_msg(int server_sock, int programid, int client) {

    msg_t msg;

    msg.type = TCHAU;
    msg.orig_uid = programid;
    msg.dest_uid = SERVER; 
    msg.text_len = 
    msg.text = client + '0'.

    size_t lenght = sizeof(msg);

    int ret = write(server_sock, &msg, lenght);
    if (ret < 0) {
        printf("\n ### ERROR: Failed to send TCHAU message. errno: %i \n", errno);
        return -1;
    }

    return 0;
}
