#ifndef MSG_H_
#define MSH_H_

/*============================================================================*
 * Constants                                                                  *
 *============================================================================*/

    // Mensages codes.
    #define OI 0
    #define TCHAU 1
    #define MSG 2

    // Program identifier.
    #define SERVER 0
    #define READER 1
    #define SENDER 2

/*============================================================================*
 * Structs                                                                    *
 *============================================================================*/

    // Menssage components.
    struct msg_t{
        unsigned short int type;
        unsigned short int orig_uid;
        unsigned short int dest_uid;
        unsigned short int text_len;
        unsigned char text[141];
    };

/*============================================================================*
 * Public Functions                                                           *
 *============================================================================*/

    // Receive message from server
    extern int receive_message(int, struct msg_t *);

    // Send message.
    extern int send_message(int, struct msg_t);
#endif
