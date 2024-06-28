#ifndef SERVER_H_
#define SERVER_H_

/*============================================================================*
 * Constants                                                                  *
 *============================================================================*/

    // Max clients waiting for accept connection.
    #define MAX_QUEUE 20

    // Set time in seconds to send informations about the server.
    #define TIME_INFO 60

/*============================================================================*
 * Macros                                                                     *
 *============================================================================*/

    // Help message.
    #define HELPSERVER(argv)\
    { \
        printf("\n"); \
        printf("Usage:\n"); \
        printf("  %s [1024 < PORT < 65536]\n", argv); \
        printf("  |  Execute Program\n\n"); \
    } \

#endif
