#ifndef SERVER_H
# define SERVER_H
# include <string>
# include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>
# include <vector>
#include "client.hpp"

class Client;

class Server
{

public:
    // Server();
    Server(int port, const std::string &password);
    // Server(const Server &other);
    // Server &operator=(const Server &other);
    ~Server();

    int     get_port() const;
    void    set_port(int new_port);
    std::string     get_password() const;
    void            set_password(std::string new_password);
    void            initSocket(int port);

private:
    int port_;
    std::string password_;
    std::vector<pollfd>					pollfd_;
    std::vector<Client> client_;

    int server_socket_fd;
};




int parsing(std::string arg1, std::string arg2);
int check_digit(std::string arg1);

#endif