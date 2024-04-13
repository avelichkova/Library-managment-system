#include "SingletonCommands.hpp"
#include <iostream>

SingletonCommands::SingletonCommands()
{
    this->stopProgram = false;
}

SingletonCommands& SingletonCommands::getInstance()
{
    static SingletonCommands object;

    return object;
}

const std::string SingletonCommands::VALID_COMMANDS[NUMBER_OF_COMMANDS] = 
{"book", "person", "borrow", "return", "remove", "save", "show"};

bool SingletonCommands::isISBNDefined(ISBN isbn)
{
    for (std::size_t i = 0; i < this->book.getSize(); i++)
    {
        if(isbn == this->book[i]->getISBN()) 
        {
            return true;
        }
    }
    return false;
}

bool SingletonCommands::isIDDefined(unsigned int id)
{
    for (std::size_t i = 0; i < this->person.getSize(); i++)
    {
        if(id == this->person[i]->getId())
        {
            return true;
        }
    }

    return false;
}

bool SingletonCommands::isValid(Commands command)
{
    std::string mainCommand = command[0];
    std::size_t size = command.getSize();
    bool commandFound = false;

    for (std::size_t i = 0; i < this->NUMBER_OF_COMMANDS; i++)
    {
        if(mainCommand == SingletonCommands::VALID_COMMANDS[i])
        {
            commandFound = true;
            break;
        }
    }

    if(!commandFound)
    {
        std::cout << "Invalid command\n";
        return false;
    } 

    if(mainCommand == "book")
    {
        
        if(size != this->FOUR_ARGUMENTS)
        {
            std::cout << size;
            std::cout << "Invalid number of arguments! \n";
            return false;
        }

        ISBN isbn(command[1]);
        if(isbn.validate() == false) 
        {
            std::cout << "Invalid ISBN! \n";
            return false;
        }

        if(isISBNDefined(isbn)) 
        {
            std::cout << "This ISBN is already definded. \n";
            return false;
        }
    }

    if(mainCommand == "person")
    {
        if(size != this->THREE_ARGUMENTS)
        {
            std::cout << size;
            std::cout << "Invalid number of arguments! \n";
            return false;
        }
        if(isIDDefined(std::stoi(command[2])))
        {
            std::cout << "This ID is already definded. \n";
            return false;
        }
    }

    if(mainCommand == "borrow")
    {
        if(size != this->THREE_ARGUMENTS)
        {
            std::cout << "Invalid number of arguments! \n";
            return false;
        }

        //return
        if(!isIDDefined(std::stoi(command[1])))
        {
            std::cout << "There is no exicting person with this ID! \n";
            return false;
        }

        ISBN isbn(command[2]);
        if(!isISBNDefined(isbn))
        {
            std::cout << "There is no exicting book with this ISBN! \n";
            return false;
        }
    }
    
}

void SingletonCommands::addBook(ISBN isbn, std::string title, std::string author)
{
    Book* addBook = this->book.allocate(isbn, title, author);
}

void SingletonCommands::addPerson(std::string name, unsigned int id)
{
    Person* addPerson = this->person.allocate(name, id);
}

void SingletonCommands::borrowBook(unsigned int id, ISBN isbn)
{
    Person* p = this->person.getPerson(id);
    Book* book = this->book.getBook(isbn);
    p->addBook(*book);
}

void SingletonCommands::returnBook(unsigned int id, ISBN isbn)
{
    Person* p = this->person.getPerson(id);
    Book* book = this->book.getBook(isbn);
    p->returnBook(*book);
}

void SingletonCommands::remove(std::string id)
{
    bool found = false;

    for (std::size_t i = 0; i < this->book.getSize(); i++)
    {
        if(this->book[i]->getISBN() == id) 
        {
            found = true;
            this->person.removePerson(i);
            break;
        }
    }

    for (std::size_t i = 0; i < this->person.getSize(); i++)
    {
        if(this->person[i]->getId() == std::stoi(id))
        {
            found = true;
            this->book.removeBook(i);
            break;
        }
    }
    
    if(!found) std::cout << "This object does not exist! \n";
    
}

void SingletonCommands::execute(Commands command)
{
    if(!isValid(command))
    {
        return;
    }

    std::string mainCommand = command[0];

    if(mainCommand == "book")
    {
        std::cout << "InBook";
        this->addBook(command[1], command[2], command[3]);
        std::cout << "Successfully added! ";
    }
    else if(mainCommand == "person")
    {
        this->addPerson(command[1], std::stoi(command[2]));
        std::cout << "Successfully added! ";
        
    }
    else if(mainCommand == "borrow")
    {
        this->borrowBook(std::stoi(command[1]), command[2]);
        std::cout << "Successfully added! ";
    }
    else if(mainCommand == "return")
    {
        this->returnBook(std::stoi(command[1]), command[2]);
        std::cout << "Successfully added! ";
    }
    else if(mainCommand == "remove")
    {
        this->remove(command[1]);
        std::cout << "Successfully added! ";
    }
}

void SingletonCommands::start()
{
    while (!this->stopProgram)
    {
        std::string command;
        std::cout << "> ";
        std::getline(std::cin, command);
        Commands cmd(command);
            this->execute(command);
        
    }
}

void SingletonCommands::openExictingFile(std::string& path)
{
    std::ifstream file(path);

        if (!file.is_open())
        {
            std::cout << "Problem while opening the file" << std::endl;
            return;
        }
        char tempLine[1024];
        while (!file.eof())
        {
            file.getline(tempLine, 1024);
            std::cout << tempLine << std::endl;
        }

        std::cout << "The file will rewrite. Are you sure you want to continue? Yes or No.\n";
        std::string responce;
        std::cin >> responce;
        if(responce == "Yes")
        {
            size_t currentPosition = file.tellg();

            file.seekg(0, std::ios::end);

            size_t endPosition = file.tellg();

            bool isEmpty = (currentPosition == endPosition);

            if(!isEmpty)
            {
                std::string line;
                std::string subline;
                file.seekg(0, std::ios::beg);
                while(!file.eof())
                {
                    if(!sublineStart(line))
                    {
                        std::getline(file, line);
                        extractInfo(line);
                    } else 
                    {
                        std::getline(file, subline);
                        extractSubinfo(subline);
                    }
                }
                file.close();
                std::cout << "Successfully read books from file. \n";
                return;
            } else std::cout << "Empty file! \n";
            
        } else return;

}

std::size_t SingletonCommands::numOfSeparators(std::string& line)
{
    int num;
    for (std::size_t i = 0; i < line.size(); i++)
    {
        if(line[i] == '|') num++;
    }
    return num;
}

bool SingletonCommands::sublineStart(std::string& line)
{
    return line[0] == '>';
}

void SingletonCommands::extractSubinfo(std::string& line)
{
    if(numOfSeparators(line) == 1)
    {
        std::string id;

        size_t separatorPos = line.find('|');

        if (separatorPos != std::string::npos) 
        {
            id = line.substr(separatorPos + 1);
        }

        std::size_t index = 0;
        for (std::size_t i = 0; i < this->person.getSize(); i++)
        {
            if(this->person[i]->getId() == std::stoi(id)) index = i;
        }
        
        this->book[this->book.getSize() - 1]->addReader(this->person[index]);
    } else if(numOfSeparators(line) == 2)
    {
        std::string isbn;

        size_t pos1 = line.find('|');

        if(pos1 != std::string::npos)
        {
            isbn = line.substr(0, pos1);
        }

        std::size_t index;
        for (std::size_t i = 0; i < this->book.getSize(); i++)
        {
            if(this->book[i]->getISBN() == isbn) index = i;
        }

        this->person[this->person.getSize() - 1]->addBook(*this->book[index]);
    }
}

void SingletonCommands::extractInfo(std::string& line)
{
        if(numOfSeparators(line) == 1)
        {
            std::string name, id;

            std:: size_t separatorPos = line.find('|');

            if (separatorPos != std::string::npos) 
            {
                name = line.substr(0, separatorPos);
                id = line.substr(separatorPos + 1);
            }

            addPerson(name, std::stoi(id));
        } else if(numOfSeparators(line) == 2)
        {
                std::string isbn, title, author;

                std::size_t pos1 = line.find('|');
                std::size_t pos2 = line.find('|', pos1 + 1);

                if(pos1 != std::string::npos && pos2 != std::string::npos)
                {
                    isbn = line.substr(0, pos1);
                    title = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    author = line.substr(pos2 + 1);
                }
        }
}