#include <iostream>
#include <ArgumentHandler.h>
#include <SerialMonitor.h>

int main(int argc, char *argv[])
{
    ArgumentHandler handler;
    Configuration config;
    SerialMonitor serialMonitor;

    // Start from 1 to ignore the path
    for(int i = 1; i < argc; i += 2)
    {
        if(std::string(argv[i]) == "-L")
        {
            serialMonitor.ListComPorts();
            // Exit application
            exit(0);
        }

        handler.AddArgument(std::string(argv[i]), std::string(argv[i + 1]));
    }

    handler.CreateConfiguration(config);
    serialMonitor.AddConfiguration(config);
    serialMonitor.Create();
    serialMonitor.Read();
    return 0;
}
