#pragma once

#include <memory>
#include <iostream>
#include <Socket.h>

class SocketConnection
{
    public:
        bool isConnected{false};
        std::string addr;

        void send(const std::string& msg);
        std::string recv();
        void connect(const std::string& addr);
        void disconnect();

    protected:
        virtual Socket* createSocket() = 0;

    private:
        Socket* sock;
};

class UdpConnection : public SocketConnection
{
    public:
        Socket* createSocket() override;
};

class TcpConnection : public SocketConnection
{
    public:
        Socket* createSocket() override;
};