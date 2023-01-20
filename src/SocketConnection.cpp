#include "SocketConnection.h"

void SocketConnection::connect(const std::string& addr)
{
    sock = createSocket();
    isConnected = true;
    std::cout << "Connected." << std::endl;
}
void SocketConnection::disconnect()
{
    delete sock;
    isConnected = false;
    std::cout << "Disconnected." << std::endl;
}

void SocketConnection::send(const std::string& msg) 
{
    sock->send(msg);
    std::cout << "Sent '" << msg << "'." << std::endl;
}
std::string SocketConnection::recv()
{
    sock->recv();
    std::cout << "Receiving..." << std::endl;
    return "Test";
}

Socket* UdpConnection::createSocket()
{
    return new UdpSocket(addr);
}

Socket* TcpConnection::createSocket() 
{
    return new TcpSocket(addr);
}
