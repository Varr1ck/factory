#pragma once

#include <string>
#include <iostream>

class Socket
{
  protected:
    std::string addr;

    Socket(const std::string& addr);

  public:
    virtual void send(const std::string& msg) = 0;
    virtual std::string recv() = 0;
};

class UdpSocket : public Socket
{
  public:
    UdpSocket(const std::string& addr) : Socket(addr) {}

    void send(const std::string& msg) override;
    std::string recv() override;
};

class TcpSocket : public Socket
{
  public:
    TcpSocket(const std::string& addr) : Socket(addr) {}

    void send(const std::string& msg) override;
    std::string recv() override;
};
