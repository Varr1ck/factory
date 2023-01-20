#pragma once

#include <memory>
#include <thread>
#include <iostream>
#include <atomic>
#include "SocketConnection.h"

class Heartbeat
{
    private:
        SocketConnection* sc;
        std::thread t;
        std::atomic<bool> continueBeating{true};
        int interval_ms;
        void sendBeat();

    public:
        bool isBeating{false};
        Heartbeat(SocketConnection* sc);
        void startBeat(int interval);
        void stopBeat();
};