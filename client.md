#pragma comment(lib,"Ws2_32.lib")
#include <WS2tcpip.h>
#include <WinSock2.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define PORT 666
#define SERVERADDR "127.0.0.1"

int main(int argc, char *argv[]){
	WSADATA wsadata;
	struct Client
	{
		char name[32];
		SOCKET CSocket;
	};
	int res;
	char buff[1024];
        res = WSAStartup(0x0202, &wsadata);
        printf("WSAStartup 1 times:%d\n", res);

        if (res != 0) {
            printf("WSAStartup error:%d\n", WSAGetLastError());
            exit(1);
        }
		Client client;
		client.CSocket=socket(AF_INET,SOCK_STREAM,0);
	
	if(client.CSocket==INVALID_SOCKET) printf("Error at creating socket\n");
	else printf("socket is successful created\n");
	sockaddr_in dest;
	dest.sin_family=AF_INET;
    dest.sin_addr.s_addr=inet_addr(SERVERADDR);
	dest.sin_port=htons(PORT);
	printf("Input ur nickname= ");gets(client.name);
	if(SOCKET_ERROR==connect( client.CSocket, ( struct sockaddr* )&dest, sizeof(dest)))
	{
		printf("Connection error:%d\n", WSAGetLastError());
		exit(1);
	} else printf("Connection with %s is successful\n\
    Type 'leave' for quit\n\n",SERVERADDR);
    while((recv(client.CSocket,&buff[0],sizeof(buff),0))!=SOCKET_ERROR)
    {
      // выводим на экран 
      printf("Server=>%s : %s\n",client.name,buff);
      // читаем пользовательский ввод с клавиатуры
      printf(" %s =>Server:",client.name); fgets(&buff[0],sizeof(buff),
             stdin);
      if (!strcmp(&buff[0],"leave\n"))
      {
        printf("Exit...");
        closesocket(client.CSocket);
        WSACleanup();
        return 0;
      }

      // передаем строку клиента серверу
	  printf("Sending :%s\n",buff);
      send(client.CSocket,&buff[0],sizeof(buff),MSG_DONTROUTE);
	  
    }

    printf("Recv error %d\n",WSAGetLastError());
    closesocket(client.CSocket);
    WSACleanup();
    return -1;
  }
