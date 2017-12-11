#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
  WSADATA wsaData;
  int err;

  printf("Test for WSAStartup\n");
  printf("==========================\n");
  for (int major = 1; major <= 2; major++)
  {
    for (int minor = 0; minor <= 2; minor++)
    {
      err = WSAStartup(MAKEWORD(major, minor), &wsaData);
      if (err == 0)
      {
        printf("WSAStartup(%d,%d) successful\n", major, minor);
        WSACleanup();
      }
      else
      {
        printf("WSAStartup(%d,%d failed\tWSAError=%d\n", major, minor, WSAGetLastError());
      }
    }
  }
  printf("==========================\n");
  system("pause");
}
