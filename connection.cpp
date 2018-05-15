#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "connection.h"
#include "util.h"
#include <WinSock2.h>
#include <ws2tcpip.h>

Connection::Connection()
{
	
}

Connection::Connection(char * ip, int port)
{
	this->hostIp = new char(strlen(ip));
	util::strcpy(hostIp, ip);
	this->port = port;
}

Connection::~Connection()
{
}

bool Connection::init(void)
{
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
		return false;
	this->mainSocket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mainSocket == INVALID_SOCKET)
		return false;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(hostIp);
	service.sin_port = htons(port); 
	if (connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
		return false;
	else
		return true;
}

bool Connection::setIp(void)
{
	return false;
}

bool Connection::setIp(char *ip)
{
	this->hostIp = new char(strlen(ip));
	util::strcpy(hostIp, ip);
	return TRUE;
}

bool Connection::setAddr(void)
{
	return false;
}

bool Connection::setAddr(char * addr)
{
	this->hostAddr = new char(strlen(addr));
	util::strcpy(hostIp, addr);
	return TRUE;
}

bool Connection::setRequest(void)
{
	return false;
}

bool Connection::setRequest(char * request)
{
	return false;
}

bool Connection::setPort(int port)
{
	this->port = port;
	return true;
}

char * Connection::getResponse(void)
{
	return nullptr;
}

char * Connection::getIp(void)
{
	return hostIp;
}

char * Connection::getAddr(void)
{
	return hostAddr;
}

char * Connection::getRequest(void)
{
	return nullptr;
}

bool Connection::sendRequest(char * path)
{
	//char request = [] ="GET" + path;
//	send(mainSocket, request, strlen(request) + 1, 0);
	return true;
}

bool Connection::receiveResponse(void)
{

	return false;
}
