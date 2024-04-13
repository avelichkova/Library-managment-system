#pragma once
#include "Book.hpp"
#include "Person.hpp"

class PersonAllocator
{
private:
    std::vector<Person*> readers;
public:
    bool validID(unsigned int id);
    Person* allocate(std::string name, unsigned int id);
    Person* getPerson(unsigned int id) const;
    void removePerson(std::size_t index);

    std::size_t getSize() const;
    Person* operator[](std::size_t index);
    ~PersonAllocator();
};



