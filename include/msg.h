#ifndef MSG_H_
#define MSH_H_

    // Mensages codes.
    #define OI 0
    #define TCHAU 1
    #define MSG 2

    // Mensage components.
    struct {
        unsigned short int type;
        unsigned short int orig_uid;
        unsigned short int dest_uid;
        unsigned short int text_len;
        unsigned char text[141];
    } msg_t;

    void print();

#endif
