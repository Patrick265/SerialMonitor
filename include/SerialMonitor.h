//
// Created by Patrick on 16/05/2021.
//

#ifndef SERIALMONITOR_H
#define SERIALMONITOR_H

#include <cstdint>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#elif __unix__
#error "Not implemented"
#endif

#include "Configuration.h"


class SerialMonitor
{
    private:
        Configuration config;
        std::vector<char> recvBuff;
#if _WIN32
        HANDLE port;
        DCB serialParams;
#elif __unix__
#endif

    public:
        SerialMonitor(const Configuration &config);
        SerialMonitor();
        uint8_t Create();
        void Read();
        void Close();
        void ListComPorts();
        void AddConfiguration(const Configuration &config);
};


#endif //SERIALMONITOR_H
