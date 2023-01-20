#include "Socket.h"

Socket::Socket(const std::string& addr) : addr(addr) {}

void UdpSocket::send(const std::string& msg) 
{
    std::cout << "UdpSocket sent '" << msg << "'." << std::endl;
}
std::string UdpSocket::recv()
{
    std::cout << "UdpSocket receiving..." << std::endl;
    return "Test";
}

void TcpSocket::send(const std::string& msg) 
{
    std::cout << "TcpSocket sent '" << msg << "'." << std::endl;
}
std::string TcpSocket::recv()
{
    std::cout << "UdpSocket receiving..." << std::endl;
    return "Test";
}