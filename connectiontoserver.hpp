#ifndef CONNECTIONTOSERVER_HPP
#define CONNECTIONTOSERVER_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <QDebug>

#define PORT 7777

class ConnectionToServer
{
public:
  int sock;
  char buffer[1024];
  struct sockaddr_in server_address;

  int _idUserConnection;
  ConnectionToServer();

  void ConnServer();
  bool ConnStatus();
  void CloseConnection();
  void EnterMessage(std::string message);
  std::string ServerUpdate();
};

#endif // CONNECTIONTOSERVER_HPP
