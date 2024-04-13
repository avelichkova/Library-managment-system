#pragma once
#include <string>
#include <vector>
#include "Commands.hpp"
#include "BookAllocator.hpp"
#include "PersonAllocator.hpp"

class SingletonCommands
{
private:
    static const std::size_t NUMBER_OF_COMMANDS = 7;
    static const std::string VALID_COMMANDS[NUMBER_OF_COMMANDS]; 
    static const std::size_t ONE_ARGUMENT = 1; 
    static const std::size_t TWO_ARGUMENTS = 2; 
    static const std::size_t THREE_ARGUMENTS = 3; 
    static const std::size_t FOUR_ARGUMENTS = 4; 

    BookAllocator book;
    PersonAllocator person;

    bool stopProgram;
public:
    SingletonCommands();

    SingletonCommands(const SingletonCommands& other) = delete;
    SingletonCommands& operator = (const SingletonCommands& other) = delete;

    static SingletonCommands& getInstance();

    void exit();
    void start();

    void addBook(ISBN isbn, std::string title, std::string author);
    void addPerson(std::string name, unsigned int id);
    void borrowBook(unsigned int id, ISBN isbn);
    void returnBook(unsigned int id, ISBN isbn);
    void remove(std::string id);
    void save(std::string filePath);

    bool isISBNDefined(ISBN isbn);
    bool isIDDefined(unsigned int id);

    bool isValid(Commands command);
    void execute(Commands command);

    // Files
    void openExictingFile(std::string& path);
    std::size_t numOfSeparators(std::string& line);
    bool sublineStart(std::string& line);
    void extractInfo(std::string& line);
    void extractSubinfo(std::string& line);
};

