//
// Created by Patrick on 16/05/2021.
//

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <cstdint>
#include <string>

typedef enum
{
    PNone = 0U,
    Podd = 1,
    PEven = 2,
    PMark = 3,
    PSpace = 4,
} Parity_e;

typedef enum
{
    SB_None,
    SB_One,
    SB_OnePointFive,
} StopBits_e;

class Configuration
{
    private:
        StopBits_e stopBits;
        Parity_e  parity;
        uint32_t baudrate;
        uint32_t dataBits;
        std::string comPort;

    public:
        Configuration(StopBits_e stopBits, Parity_e parity, uint32_t baudrate, uint32_t dataBits,
                      const std::string &comPort);

        Configuration();

        StopBits_e getStopBits() const;

        void setStopBits(StopBits_e stopBits);
        void setStopBits(std::string value);

        Parity_e getParity() const;

        void setParity(Parity_e parity);
        void setParity(std::string parity);

        uint32_t getBaudRate() const;

        void setBaudRate(uint32_t baud);

        uint32_t getDataBits() const;

        void setDataBits(uint32_t dataBits);

        const std::string &getComPort() const;

        void setComPort(const std::string &comPort);
};


#endif //CONFIGURATION_H
