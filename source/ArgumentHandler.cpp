//
// Created by Patrick on 16/05/2021.
//

#include <iostream>
#include "ArgumentHandler.h"


ArgumentHandler::ArgumentHandler()
{

}

void ArgumentHandler::AddArgument(std::string prefix, std::string arg)
{
    this->arguments.emplace_back(prefix, arg);
}

void ArgumentHandler::CreateConfiguration(Configuration &config)
{
    int32_t argSize = this->arguments.size();
    if(argSize == 0)
    {
        this->CreateDefaultConfig(config);
        return;
    }

    char prefix;
    std::string value;
    for(int i = 0; i < argSize; i++)
    {
        prefix = std::get<0>(this->arguments[i])[1];
        value = std::get<1>(this->arguments[i]);

        switch(prefix)
        {
            default:
                std::cout << "Invalid value => " << prefix << " " << value << std::endl;
                exit(1);
                break;
            // Baudrate
            case 'b':
                config.setBaudRate(static_cast<uint32_t>(std::stoul(value)));
                break;
            // COM PORT
            case 'c':
                config.setComPort(value);
                break;
            // Parity
            case 'p':
                config.setParity(value);
                break;
            case 'd':
                config.setDataBits(static_cast<uint32_t>(std::stoul(value)));
            case 's':
                config.setStopBits(value);
        }
    }
}

void ArgumentHandler::CreateDefaultConfig(Configuration &config)
{

}



