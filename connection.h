#ifndef _CONNECTION
#define _CONNECTION
//#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
//#include <string>
//#include <fstream>
#include "connection.h"
//#pragma comment(lib, "Ws2_32.lib")
using namespace std;
class Connection
{
public:
	Connection(); //constructor
	Connection(char * ip, int port);
	~Connection(); //destructor

	bool init(void);
	bool setIp(void);
	bool setIp(char* ip);
	bool setAddr(void);
	bool setAddr(char *addr);
	bool setRequest(void);
	bool setRequest(char *request);
	bool setPort(int port);

	char* getResponse(void);
	char* getIp(void);
	char* getAddr(void);
	char* getRequest(void);

	bool sendRequest(void);
	bool sendRequest(char * path);

	bool receiveResponse(void);


private:
	char *hostIp;
	char *hostAddr;
	char *request;
	int port;
	WSADATA wsaData;
	SOCKET mainSocket;
	sockaddr_in service;
};

#endif // !_CONNECTION
