/*
 * clientsocket.cpp
 *
 *  Created on: 01-Apr-2017
 *      Author: navin
 */

#include "clientsocket.h"
#include <string>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

client_socket::client_socket() {
	serv_addr = new sockaddr_in();
	serv_addr->sin_family = AF_INET;
	sockFd = -1;
}

bool client_socket::connectToServer(std::string serv_ip,int port)
{
	sockFd = socket(AF_INET,SOCK_STREAM,0);
	if(sockFd == -1)
	{
		std::cout << "Error : Creating socket failed" << std::endl;
		return -1;
	}
	serv_addr->sin_port = htons(port);
	if(inet_pton(AF_INET, serv_ip.c_str(), &serv_addr->sin_addr)<=0)
	{
		std::cout << "Error : Invalid address/ Address not supported \n";
		return -1;
	}

	if(connect(sockFd,(struct sockaddr *)serv_addr, sizeof(*serv_addr)) == -1)
	{
		std::cout << "Error : Connecting to ["<<serv_ip<<"] failed" << std::endl;
		return -1;
	}
	return true;
}
std::string client_socket::readMessage()
{
	if(sockFd == -1)
	{
		std::cout << "Error : Socket not defined"<< std::endl;
		exit(1);
	}
	std::string message;
	char buffer[1025];int readLen=1024;
	while(readLen == 1024)
	{
		readLen = read(sockFd,buffer,1024);
		buffer[readLen]= '\0';
		message += std::string(buffer);
	}
	return message;
}
bool client_socket::writeMessage(std::string str)
{
	if(sockFd == -1)
	{
		std::cout << "Error : Socket not defined"<< std::endl;
		exit(1);
	}
	if(send(sockFd,str.c_str(),str.length(),0) == -1)
	{
		std::cout << "Error : Message ["<<str<<"] writing failed"<< std::endl;
	}
}

client_socket::~client_socket() {
	close(sockFd);
	delete serv_addr;
}

