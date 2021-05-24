//
// Created by Patrick on 16/05/2021.
//

#include "SerialMonitor.h"

#include <chrono>
#include <ctime>
#include <iostream>

SerialMonitor::SerialMonitor(const Configuration &config) : config(config)
{

}

SerialMonitor::SerialMonitor() = default;


uint8_t SerialMonitor::Create()
{
    if(this->config.getComPort() == "")
    {
        std::cout << "No com port given" << std::endl;
        return 1;
    }
#if _WIN32

    std::string comPort = "\\\\.\\" + this->config.getComPort();
    this->port = CreateFile(comPort.c_str(),
                            GENERIC_READ, 0, NULL,
                            OPEN_EXISTING, 0, NULL);

    if(this->port == INVALID_HANDLE_VALUE)
    {
        std::cout << "Could not open " + this->config.getComPort() << std::endl;
        return 1;
    }

    this->serialParams.DCBlength = sizeof(this->serialParams);
    // Check if we can set the state of com port
    bool status = GetCommState(this->port, &this->serialParams);
    if(!status)
    {
        std::cout << "Could not get COM state" << std::endl;
        return 1;
    }
    //  Setting the configuration
    this->serialParams.BaudRate = this->config.getBaudRate();
    this->serialParams.ByteSize = this->config.getDataBits();
    this->serialParams.StopBits = this->config.getStopBits();
    this->serialParams.Parity = this->config.getParity();

    // Setting com state
    status = SetCommState(this->port, &this->serialParams);
    if(!status)
    {
        std::cout << "Could not set COM State" << std::endl;
    }
#endif
    return 0;
}

void SerialMonitor::Read()
{
    unsigned long bufferRecv;
    bool status = false;
    char recvChar;
    do
    {
        status = ReadFile(this->port, &recvChar, sizeof(recvChar), &bufferRecv, NULL);
        if(!status)
        {
            std::cout << "Error reading com port" << std::endl;
            this->Close();
        }

        std::cout << recvChar;

    } while(bufferRecv > 0);
}

void SerialMonitor::Close()
{
    CloseHandle(this->port);
    exit(1);
}


void SerialMonitor::ListComPorts()
{
    const uint8_t maxComNum = 255;
    std::string prefix = "\\\\.\\COM";
    std::string port = "";
    HANDLE handle;
    for(uint16_t i = 1; i < maxComNum; i++)
    {

        port = prefix + std::to_string(i);
        handle = CreateFile(port.c_str(),
                            GENERIC_READ, 0, NULL,
                            OPEN_EXISTING, 0, NULL);
        if(handle != INVALID_HANDLE_VALUE)
        {
            std::cout << "Found port: COM" << i << std::endl;
        }
        CloseHandle(handle);
    }
}

void SerialMonitor::AddConfiguration(const Configuration &config)
{
    this->config = config;
}