/*
 * clientsocket.h
 *
 *  Created on: 01-Apr-2017
 *      Author: navin
 */

#ifndef CLIENTSOCKET_H_
#define CLIENTSOCKET_H_
#include <netinet/in.h>
#include <string>

class client_socket {
public:
	client_socket();
	virtual ~client_socket();

	bool connectToServer(std::string serv_ip,int port);
	std::string readMessage();
	bool writeMessage(std::string str);

private:
	struct sockaddr_in *serv_addr;
	int sockFd;
};

#endif /* CLIENTSOCKET_H_ */
