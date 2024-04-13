#include "Person.hpp"

Person::Person(std::string name, unsigned int id)
: name(name), id(id) {}

void Person::addBook(Book& book)
{
    this->books.push_back(&book);
}

void Person::returnBook(const Book& other)
{
    for (std::size_t i = 0; i < this->books.size(); i++)
    {
        if(this->books[i]->getISBN() == other.getISBN()) 
        {  
            this->books.erase(this->books.begin() + i);
            break;
        }
    }
}

void Person::printBooks() const
{
    for (std::size_t i = 0; i < this->books.size(); i++)
    {
        std::cout << *this->books[i];
    }
}

unsigned int Person::getId() const
{
    return this->id;
}
