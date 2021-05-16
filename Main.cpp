#include <iostream>
#include <ArgumentHandler.h>
#include <SerialMonitor.h>

int main(int argc, char *argv[])
{
    ArgumentHandler handler;
    Configuration config;
    // Start from 1 and ignore the path
    for(int i = 1; i < argc; i += 2)
    {
        handler.AddArgument(std::string(argv[i]), std::string(argv[i + 1]));
    }

    handler.CreateConfiguration(config);
    SerialMonitor serialMonitor(config);
    serialMonitor.Create();
    serialMonitor.Read();
    return 0;
}
