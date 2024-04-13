#pragma once 
#include "Book.hpp"
#include <vector>

class Person
{
private:
    std::string name;
    unsigned int id;
    std::vector<Book*> books;

public:
    Person(std::string name, unsigned int id);
    void addBook(Book& book);
    void returnBook(const Book& other);
    void printBooks() const;
    void copyBooks(std::vector<Book*> books);

    unsigned int getId() const;
};

