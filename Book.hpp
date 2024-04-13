#pragma once
#include <string>
#include <iostream>
#include "ISBN.hpp"

class Person;

class Book
{
private:
    ISBN isbn;
    std::string title;
    std::string author;
    Person* reader;
    
    
public:
    Book(ISBN isbn, std::string title, std::string author);
    ISBN getISBN() const;
    friend std::ostream& operator<<(std::ostream& out, const Book& other);
    void addReader(Person* reader);
};
