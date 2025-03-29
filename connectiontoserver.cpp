#include "connectiontoserver.hpp"

ConnectionToServer::ConnectionToServer() { }

int ConnectionToServer::ConnServer() {
  sock = 0;
  buffer[1024] = {0};
  if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      qDebug() << "Error creating socket";
      connectionstatus = 1;
      return -1;
    }
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);

  if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
      qDebug() << "Error search server";
      connectionstatus = 1;
      return -1;
    }

  if(connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
      qDebug() << "Error connection to server";
      connectionstatus = 1;
      return -1;
    }
  connectionstatus = 0;
  qDebug() << "Connection to server is complit";
  return 0;
}

void ConnectionToServer::CloseConnection() { close(sock); }

void ConnectionToServer::EnterMessage(std::string message) {
  if(connectionstatus == 0)
    send(sock, message.c_str(), message.length(), 0);
}

std::string ConnectionToServer::ServerUpdate() {
  memset(buffer, 0, sizeof(buffer));
  int bytes = read(sock, buffer, 1024);
  if(bytes > 0) {
      qDebug() << buffer;
      return buffer;
    }
  else qDebug() << "Error get message from server";
  return "";
}
