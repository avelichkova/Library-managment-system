#include "BookAllocator.hpp"

BookAllocator::~BookAllocator()
{
    for (std::size_t i = 0; i < this->books.size(); i++)
    {
        delete this->books[i];
    }
}

bool BookAllocator::validISBN(ISBN& isbn)
{
    for (std::size_t i = 0; i < this->books.size(); i++)
    {
        if(isbn == this->books[i]->getISBN())
        {
            std::cout << isbn.getISBN() << " is already existing!\n";
            return false;
        }
    }

    return true;
    
}

Book* BookAllocator::allocate(ISBN isbn, std::string title, std::string author)
{
    if(validISBN(isbn))
    {
        Book* newBook = new Book(isbn, title, author);
        this->books.push_back(newBook);

        return newBook;
    }
}

Book* BookAllocator::getBook(ISBN isbn)
{
    for (std::size_t i = 0; i < this->books.size(); i++)
    {
        if(this->books[i]->getISBN() == isbn) return this->books[i];
    }
}

void BookAllocator::removeBook(std::size_t index)
{
    this->books.erase(this->books.begin() + index);
}


std::size_t BookAllocator::getSize() const
{
    return this->books.size();
}

Book* BookAllocator::operator[](std::size_t index)
{
    return this->books[index];
}