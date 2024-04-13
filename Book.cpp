#include "Book.hpp"

Book::Book(ISBN isbn, std::string title, std::string author)
: isbn(isbn), title(title), author(author){}

ISBN Book::getISBN() const
{
    return this->isbn;
}

std::ostream& operator<<(std::ostream& out, const Book& other)
{
    out << "ISBN: " << other.isbn.getISBN() << " Title: " << other.title << " Author: " << other.author;
}

void Book::addReader(Person* newReader)
{
    this->reader = newReader;
}