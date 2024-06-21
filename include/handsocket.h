#ifndef SERVER_H_
#define SERVER_H_

    #define SERVER_TIMEOUT 5
    #define SERVER_PORT 50234
    #define MAX_QUEUE 20

    // Open a socket.
    extern int open_socket();

    // Close a socket.
    extern int close_socket(int);

    // Set a timeout for finish data transmitting
    // when call a close() to the socket.
    extern int settimeout_socket(int);

    // Bind a socket to a adress.
    extern int setaddr_socket(int);

    // Set a socket to accept connections.
    int listen_socket(int);

    // Accept a new connection.
    int accept_connection(int);


#endif

