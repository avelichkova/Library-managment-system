#pragma once
#include <string>
#include <iostream>

class ISBN
{
private:
    std::string isbn;
    bool isUpper(char a);
public:
    ISBN(std::string isbn);
    bool validate(std::string isbn) const;
    bool validate() const;
    std::string getISBN() const;
    bool operator == (const ISBN& other);
};





