#include "Heartbeat.h"

Heartbeat::Heartbeat(SocketConnection* sc) : sc(sc) {}

void Heartbeat::startBeat(int interval_ms)
{
    sc->connect("TestAddr");
    this->interval_ms = interval_ms;
    t = std::thread([this] {
        sendBeat();
    });
    isBeating = true;
}

void Heartbeat::stopBeat()
{
    continueBeating = false;
    t.join();
    sc->disconnect();
    isBeating = false;
}

void Heartbeat::sendBeat()
{
    std::cout << "Started beating..." << std::endl;

    while(continueBeating) {
        sc->send("Heartbeat");
        std::cout << "Beat sent." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(this->interval_ms));       
    }

    std::cout << "Stopped beating..." << std::endl;
}

