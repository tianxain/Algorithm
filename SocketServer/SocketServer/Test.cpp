#define _CRT_SECURE_NO_WARNINGS 1
#include<WINSOCK2.H>
#include<STDIO.H>
#include<iostream>
#include <string>
using namespace std;

#pragma comment(lib,"ws2_32.lib")  

int main(int argc, char* argv[])
{
	//��ʼ��WSA  
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	//�����׽���  
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		cout<<"socket error !";
		return 0;
	}

	//��IP�Ͷ˿�  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		cout<<"bind error !";
	}

	//��ʼ����  
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		cout<<"listen error !";
		return 0;
	}

	//ѭ����������  
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];
	//cout<<"�ȴ�����...\n";
	while (true)
	{
		
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
		if (sClient == INVALID_SOCKET)
		{
			cout<<"accept error !";
			continue;
		}
		cout << "���ܵ�һ�����ӣ�";
		cout << inet_ntoa(remoteAddr.sin_addr)<<endl;

		//��������  
		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = 0x00;
			cout << "�ͻ��ˣ�"<< revData<<endl;
		}

		//��������  
		const char * sendData = "�����������ճɹ�!\n";
		send(sClient, sendData, strlen(sendData), 0);
		closesocket(sClient);
	}

	closesocket(slisten);
	WSACleanup();
	return 0;
}
