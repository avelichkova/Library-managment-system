#pragma once
#include <vector>
#include <string>
#include <fstream>

class Commands
{
private:
    std::vector<std::string> arguments;
public:
    void toLowercase(std::string &str);
    void process(const std::string& command);

    std::string& operator [] (std::size_t index);
    std::size_t getSize() const;

    Commands(std::string commandLine);
    void parseCommandLine(std::string commandLine);
    std::size_t numOfArguments(std::string line);
};


