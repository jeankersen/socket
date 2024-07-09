#include "server.hpp"

Server::Server(int port, const std::string &password) : port_(port), password_(password) {
    std::cout << "Constructor Server called" << std::endl;
    initSocket(port_);
}

Server::~Server() {
    std::cout << "Destructor Server called" << std::endl;
}

int     Server::get_port() const {
    return port_;
}

void    Server::set_port(int new_port) {
    port_ = new_port;
}

std::string     Server::get_password() const {
    return password_;
}

void            Server::set_password(std::string new_password) {
    password_ = new_password;
}

void Server::initSocket(int port)
{
    int client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[1024];
   


    // Create socket fd
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Bind to port 
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket_fd, 500);
	pollfd fdServer = {server_socket_fd, POLLIN, 0};
	pollfd_.push_back(fdServer);
    std::cout << "Server listening on port"  << std::endl;

    while(1)
    {
        if(poll(pollfd_.begin().base(), pollfd_.size(), -1) < 0)
            break;
        for(unsigned int i = 0; i < pollfd_.size(); i++)
        {
            memset(buffer, 0, sizeof(buffer));
            
        }
    }

    // Accept a connection
    socklen_t client_address_len = sizeof(client_address);
    client_socket = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_len);

    std::cout << "Got a connection from " << inet_ntoa(client_address.sin_addr) << std::endl;


    // Receive data from the client
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        std::cout << "Received message: " << buffer << std::endl;

        // Echo back the data to the client
        send(client_socket, buffer, strlen(buffer), 0);
    }
  
    // Close the connection
    close(client_socket);
    close(server_socket_fd);
}

/*

CLIENT
            int fd;
             // Accept a connection
            socklen_t client_address_len = sizeof(client_address);
            fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_len);
            client_.push_back(Client(fd));
            pollfd fdServer = {server_socket_fd, POLLIN, 0};
	        pollfd_.push_back(fdServer);

*.