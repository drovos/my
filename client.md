#include <iostream>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <string>

SOCKET Connection;
void ClientThread()
{
	char buff[256];
	while(recv(Connection,buff,sizeof(buff),NULL)!=SOCKET_ERROR)
	{
		printf("%s\n",buff);
	}
	closesocket(Connection);
	WSACleanup();
	ExitThread(NULL);
	exit(0);
}




int main()
{
	WSAData wsaData;
	WORD Version=MAKEWORD(2,1);
	if(WSAStartup(Version,&wsaData)!=0)
	{
		printf("Winsock startup failed");
		exit(1);
	}
	SOCKADDR_IN addr;
	int addrlen=sizeof(addr);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	addr.sin_port=htons(666);
	addr.sin_family=AF_INET;

	Connection = socket(AF_INET,SOCK_STREAM,NULL);
	if(connect(Connection,(SOCKADDR*)&addr,addrlen)!=0)
	{
		MessageBoxA(NULL,"Failed to connect", "Error", MB_OK |  MB_ICONERROR);
		return 0;
	}
	printf("Connected\n");
	CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ClientThread,NULL,NULL,NULL);

	char buff[256];
	while(true)
	{
		gets(buff);
		send(Connection,buff,sizeof(buff),NULL);
		
		Sleep(10);
	}
	system("pause");
	return 0;
}
