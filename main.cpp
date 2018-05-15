#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <string>
#include <fstream>
#include "connection.h"
#include "util.h"
#pragma comment(lib, "Ws2_32.lib")
#define mdanilewicz "188.116.53.38"
#define ebay "66.135.209.52"
#define ebay_stores "66.211.160.136"
#define wykop "185.66.120.38"
#define webtips "69.19.227.15"
#define google "216.58.215.78"
#define emonitoring "194.99.117.15"

using namespace std;
int main(void)
{
//	Connection test(mdanilewicz,80);
	
	//if (test.init())
		//cout << "test is connected";
	
	system("pause");
	WSADATA wsaData;
	char recBuffer[8192];// = { 0 };
	char httpRequest[] =
		"GET  /?numer=00859007734668475302  HTTP/1.1\r\n"
		"Host: emonitoring.poczta-polska.pl\r\n\r\n";
	int byteCount;
	fstream file;
	file.open("log.txt", ios_base::out);
	if (file.good())
		cout << "file is open" << endl;
	else
		cout << "could not open" << endl;



	cout << "WSAStartup->";
	if (!WSAStartup(MAKEWORD(2, 2), &wsaData))
		cout << "Success\n\r";
	else
		cout << "ERROR!\n\r";
	system("pause");

	cout << "socket->";
	SOCKET mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mainSocket == INVALID_SOCKET)
	{
		cout << "ERROR!\n\r" << WSAGetLastError() << endl;
		WSACleanup();
	}
	else
		cout << "Success\n\r";
	system("pause");

	cout << "sockaddr_in->";
	sockaddr_in service;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(emonitoring); //IP
	service.sin_port = htons(80); //port
	if (connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
	{
		cout << "ERROR!\n\r";
		WSACleanup();
		return 1;
	}
	else
		cout << "Success\n\r";
	system("pause");

	send(mainSocket, httpRequest,strlen(httpRequest)+1,0);
	cout << "sending complete!\n\rRequest lenght:"<< strlen(httpRequest)<<endl;
	
		byteCount = recv(mainSocket, recBuffer, strlen(recBuffer), 0);
		cout << "receiving complete!\n\rreceived " << byteCount << " bytes\n\rstrlen: " << strlen(recBuffer) << endl;
		//	recBuffer[byteCount + 1] = 0;
		cout << "Received data:\n\r" << recBuffer;

		byteCount = recv(mainSocket, recBuffer, strlen(recBuffer), 0);
		cout << "receiving complete!\n\rreceived " << byteCount << " bytes\n\rstrlen: " << strlen(recBuffer) << endl;
		//	recBuffer[byteCount + 1] = 0;
		cout << "Received data:\n\r" << recBuffer;
		
		file << recBuffer;
		cout << "data write ok" << endl;
		file.close();
	

	system("pause");
	return 1;
	
}