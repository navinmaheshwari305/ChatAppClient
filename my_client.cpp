//============================================================================
// Name        : my_client.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <string>
#include <netinet/in.h>
#include <unistd.h>

#include "clientsocket.h"
using namespace std;

int main(void) {
	cout << "Client Programs starts...." << endl;
	client_socket cSoc;
	if(cSoc.connectToServer("127.0.0.1",8888))
	{
		cout <<"Server says : " << cSoc.readMessage() << endl;
		string message = "Hello Server";
		cSoc.writeMessage(message);
		cout <<"Server says : " << cSoc.readMessage() << endl;
		cout <<"Server says : " << cSoc.readMessage() << endl;
	}
	cout << "Client Programs ends...." << endl;
}
