#ifndef HANDSOCKET_H_
#define HANDSOCKET_H_

/*============================================================================*
 * Constants                                                                  *
 *============================================================================*/

    // Max clients waiting for accept connection.
    #define MAX_QUEUE 20

    // Default timeout for close a connection.
    #define CONNECTION_TIMEOUT 5

/*============================================================================*
 * Public Functions                                                           *
 *============================================================================*/

    // Open a socket.
    extern int open_socket();

    // Close a socket.
    extern int close_socket(int);

    // Set a timeout for finish data transmitting
    // when call a close() to the socket.
    extern int settimeout_socket(int);

    // Bind a socket to a adress.
    extern int setaddr_socket(int, int);

    // Set a socket to accept connections.
    int listen_socket(int);

    // Accept a new connection.
    int accept_connection(int);


#endif

