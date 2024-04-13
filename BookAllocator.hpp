#pragma once
#include "Person.hpp"

class BookAllocator
{
private:
    std::vector<Book*> books;
public:
    Book* allocate(ISBN isbn, std::string title, std::string author);
    bool validISBN(ISBN& isbn);
    Book* getBook(ISBN isbn);
    void removeBook(std::size_t index);
    std::size_t getSize() const;

    Book* operator[](std::size_t index);

    ~BookAllocator();
};

