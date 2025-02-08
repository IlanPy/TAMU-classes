#include "TCPRequestChannel.h"

using namespace std;


TCPRequestChannel::TCPRequestChannel (const std::string _ip_address, const std::string _port_no) {
    // set up channel for the server side
    if(_ip_address == "") {
        struct sockaddr_in server;
        int server_sock, bind_stat, listen_stat;

        // AF_INET = IPv4, SOCK_STREAM = TCP, PROTOCOL = auto
        server_sock = socket(AF_INET, SOCK_STREAM, 0);
        sockfd = server_sock;

        // Address familiy = IPv4, IPv4 address = any, connection port
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(atoi(_port_no.c_str()));

        // Bind - assign address to socket
        bind_stat = bind(server_sock, (struct sockaddr *)&server, sizeof(server));
        if(bind_stat < 0) {
            perror("ERROR: Binding");
            exit(0);
        }

        // Listen - listen for client
        listen_stat = listen(server_sock, 128);
        if(listen_stat < 0) {
            perror("ERROR: Listening");
            exit(0);
        }
    }
    // set up channel for the client side
    else {
        struct sockaddr_in server_info;
        int client_sock, connect_stat;

        // Socket - make socket
        client_sock = socket(AF_INET, SOCK_STREAM, 0);

        // Address familiy = IPv4, IPv4 address = any, connection port
        struct hostent *server = gethostbyname(_ip_address.c_str());

        server_info.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&server_info.sin_addr.s_addr, server->h_length);
        server_info.sin_port = htons(atoi(_port_no.c_str()));

        // Connect - connect to listening socket
        connect_stat = connect(client_sock, (struct sockaddr *)&server_info, sizeof(server_info));
        if(connect_stat < 0) {
            perror("ERROR: Connecting");
            exit(0);
        }
        sockfd = client_sock;
    }
}

TCPRequestChannel::TCPRequestChannel (int _sockfd) {
    // Assign existing socket to object's socket fd
    sockfd = _sockfd;
}

TCPRequestChannel::~TCPRequestChannel () {
    // Cloes socket
    close(this->sockfd);
}

int TCPRequestChannel::accept_conn () {
    // Accept - accept connection
    struct sockaddr_in client_info;
    socklen_t client_length = sizeof(client_info);

    // Socket fd for accepted connection
    int newsockfd;

    // Accept connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_info, &client_length);

    // Return socket fd
    return newsockfd;
}

int TCPRequestChannel::cread (void* msgbuf, int msgsize) {
    ssize_t no_bytes;

    // Read from socket
    no_bytes = read(sockfd, msgbuf, msgsize);

    // Return number of bytes read
    return no_bytes;
}

int TCPRequestChannel::cwrite (void* msgbuf, int msgsize) {
    ssize_t no_bytes;

    // Write to socket
    no_bytes = write(sockfd, msgbuf, msgsize);

    // Return number of bytes written
    return no_bytes;
}
