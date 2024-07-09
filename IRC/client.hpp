#ifndef CLIENT_H
# define CLIENT_H

#include "server.hpp"



class Client 
{
	private:
		int			_sockfd;
		std::string		_nickname;

	public:
		Client(int fd);
		~Client();

};

#endif