#ifndef SERVER_H_
#define SERVER_H_

/*============================================================================*
 * Constants                                                                  *
 *============================================================================*/

    // Communication port.
    #define SERVER_PORT 50234

    // Max clients waiting for accept connection.
    #define MAX_QUEUE 20

    // Default timeout for close a connection.
    #define CONNECTION_TIMEOUT 5

    // Help menssage.
    #define HELPSERVER(argv)\
    { \
        printf("\n"); \
        printf("Usage:\n"); \
        printf("  %s [1024 < PORT < 65536]\n", argv); \
        printf("  |  Execute Program\n\n"); \
    } \

#endif
