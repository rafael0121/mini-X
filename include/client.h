#ifndef CLIENT_H_
#define CLIENT_H_

/*============================================================================*
 * Public Functions                                                           *
 *============================================================================*/

    // Connect to the server.
    extern int connect_server(int, int);

    // Get the cli args.
    extern int get_args(int, char**, int *, int *);

    // Help menssage.
    #define HELPCLIENT(argv)\
    { \
        printf("\n"); \
        printf("Usage:\n"); \
        printf("  %s [1024 < PORT < 65536] [0 < ID]\n", argv); \
        printf("  |  Execute Program\n\n"); \
    } \


#endif
