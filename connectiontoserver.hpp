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
private:
  int sock;
  struct sockaddr_in server_address;
  char buffer[1024];

public:
  ConnectionToServer();

  int connectionstatus;

  int ConnServer();
  void CloseConnection();
  void EnterMessage(std::string message);
  std::string ServerUpdate();
};

#endif // CONNECTIONTOSERVER_HPP
