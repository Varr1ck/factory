#include <iostream>

#include "Heartbeat.h"
#include "SocketConnection.h"
#include <chrono>
#include <memory>

int main(int, char**) {
    SocketConnection* sc = new TcpConnection();
    Heartbeat hb(sc);
    hb.startBeat(1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    hb.stopBeat();
    delete sc;

    return 0;
}
