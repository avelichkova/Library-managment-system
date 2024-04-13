#include "ISBN.hpp"
#include <cstring>

ISBN::ISBN(std::string isbn)
{
    if(validate(isbn)) this->isbn = isbn;
    else std::cout << "Invalid ISBN \n";
}

bool ISBN::validate(std::string isbn) const
{
    if(!(isbn.size() == 8 || isbn.size() == 9)) return false;
    for (std::size_t i = 0; i < 2; i++)
    {
        if (!((isbn[i] - '0') >= 0 && (isbn[i] - '0') <= 9)) return false;
    }

    if(isbn[3] != '-') return false;

    if (isbn.size() == 8)
    {
        for (std::size_t i = 4; i < 5; i++)
        {
            if(!(isbn[i] >= 'A' && isbn[i] <= 'Z')) return false;
        }

        if(isbn[6] != '-') return false;

        if(isbn[7] % 2 != 0) return false;
    }

    if (isbn.length() == 9)
    {
        for (std::size_t i = 4; i < 6; i++)
        {
            if(!(isbn[i] >= 'A' && isbn[i] <= 'Z')) return false;
        }

        if(isbn[7] != '-') return false;

        if(isbn[8] % 2 == 0) return false;
    }

    return true;
}

bool ISBN::validate() const
{
    if(!(isbn.size() == 8 || isbn.size() == 9)) return false;
    for (std::size_t i = 0; i < 2; i++)
    {
        if (!((isbn[i] - '0') >= 0 && (isbn[i] - '0') <= 9)) return false;
    }

    if(isbn[3] != '-') return false;

    if (isbn.size() == 8)
    {
        for (std::size_t i = 4; i < 5; i++)
        {
            if(!(isbn[i] >= 'A' && isbn[i] <= 'Z')) return false;
        }

        if(isbn[6] != '-') return false;

        if(isbn[7] % 2 != 0) return false;
    }

    if (isbn.length() == 9)
    {
        for (std::size_t i = 4; i < 6; i++)
        {
            if(!(isbn[i] >= 'A' && isbn[i] <= 'Z')) return false;
        }

        if(isbn[7] != '-') return false;

        if(isbn[8] % 2 == 0) return false;
    }

    return true;
}

std::string ISBN::getISBN() const
{
    return this->isbn;
}

bool ISBN::operator == (const ISBN& other)
{
    return this->isbn == other.isbn;
}

