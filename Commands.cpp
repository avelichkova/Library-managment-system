#include "Commands.hpp"
#include <fstream>
#include <iostream>
#include <limits>

Commands::Commands(std::string commandLine)
{
    this->parseCommandLine(commandLine);
}

void Commands::toLowercase(std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    }
}

std::string& Commands::operator[](std::size_t index)
{
    return this->arguments[index];
}

std::size_t Commands::getSize() const
{
    return this->arguments.size();
}

void Commands::parseCommandLine(std::string commandLine)
{
    std::size_t length = commandLine.length();
    std::size_t currentIndex = 0;
    std::size_t countWords = 0;

    std::string currentWord = "";

    bool insideWord = false;

    std::size_t sep_o = commandLine.find('<');

    currentWord = commandLine.substr(0, sep_o);
    this->arguments.push_back(currentWord);

    std::cout << currentWord << '\n';

    while(currentIndex < length)
    {
        char c = commandLine[currentIndex];

        if (c == '<') {
            insideWord = true;
        } else if (c == '>') {
            insideWord = false;
            if (!currentWord.empty()) {
                std::cout << currentWord << '\n';
                this->arguments.push_back(currentWord);
                currentWord.clear();
            }
        } else if (insideWord) {
            currentWord += c;
        }

        currentIndex++;
    }
}


