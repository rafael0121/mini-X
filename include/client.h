#ifndef CLIENT_H_
#define CLIENT_H_

/*============================================================================*
 * Macros                                                                     *
 *============================================================================*/

    // Help message.
    #define HELPCLIENT(argv)\
    { \
        fprintf(stdout, "\n"); \
        fprintf(stdout, "Usage:\n"); \
        fprintf(stdout, "  %s [1024 < PORT < 65536] [0 < ID]\n", argv); \
        fprintf(stdout, "  |  Execute Program\n\n"); \
    } \

/*============================================================================*
 * Public Functions                                                           *
 *============================================================================*/

    // Connect to the server.
    extern int connect_server(int, int);

    // Get the cli args.
    extern int get_args(int, char**, int *, int *);

    // Register in server.
    extern int handshake(int, int);

#endif
