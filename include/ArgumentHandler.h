//
// Created by Patrick on 16/05/2021.
//

#ifndef ARGUMENTHANDLER_H
#define ARGUMENTHANDLER_H

#include <vector>
#include <string>
#include <tuple>
#include "Configuration.h"

class ArgumentHandler
{
    private:
        std::vector<std::tuple<std::string, std::string>> arguments;
    public:
        ArgumentHandler();
        void AddArgument(std::string prefix, std::string arg);
        void CreateConfiguration(Configuration &config);
        void CreateDefaultConfig(Configuration &config);
};


#endif //ARGUMENTHANDLER_H
