//
// Created by Patrick on 16/05/2021.
//

#include "Configuration.h"

Configuration::Configuration(StopBits_e stopBits, Parity_e parity, uint32_t baudrate, uint32_t dataBits,
                             const std::string &comPort) : stopBits(stopBits), parity(parity), baudrate(baudrate),
                                                           dataBits(dataBits), comPort(comPort)
{

}

Configuration::Configuration()
{
    this->baudrate = 9600;
    this->parity = PNone,
    this->stopBits = SB_None;
    this->dataBits = 8;
    this->comPort = "";
}

StopBits_e Configuration::getStopBits() const
{
    return stopBits;
}

void Configuration::setStopBits(StopBits_e stopBits)
{
    Configuration::stopBits = stopBits;
}

Parity_e Configuration::getParity() const
{
    return parity;
}

void Configuration::setParity(Parity_e parity)
{
    Configuration::parity = parity;
}

uint32_t Configuration::getBaudRate() const
{
    return baudrate;
}

void Configuration::setBaudRate(uint32_t baud)
{
    Configuration::baudrate = baud;
}

uint32_t Configuration::getDataBits() const
{
    return dataBits;
}

void Configuration::setDataBits(uint32_t dataBits)
{
    Configuration::dataBits = dataBits;
}

const std::string &Configuration::getComPort() const
{
    return comPort;
}

void Configuration::setComPort(const std::string &comPort)
{
    Configuration::comPort = comPort;
}


