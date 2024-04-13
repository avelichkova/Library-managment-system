#include "PersonAllocator.hpp"

PersonAllocator::~PersonAllocator()
{
    for (std::size_t i = 0; i < this->readers.size(); ++i)
    {
        delete this->readers[i];
    }
}

bool PersonAllocator::validID(unsigned int id)
{
    for (std::size_t i = 0; i < this->readers.size(); i++)
    {
        if(id == this->readers[i]->getId()) 
        {
            std::cout << id << "is already existing! \n";
            return false;
        }
    }
    return true;
}

Person* PersonAllocator::allocate(std::string name, unsigned int id)
{
    if(validID(id))
    {
        Person* newPerson = new Person(name, id);
        this->readers.push_back(newPerson);
        
        return newPerson;
    }
}

Person* PersonAllocator::getPerson(unsigned int id) const
{
    for (std::size_t i = 0; i < this->readers.size(); i++)
    {
        if(this->readers[i]->getId() == id) return this->readers[i];
    }
}

void PersonAllocator::removePerson(std::size_t index)
{
    this->readers.erase(this->readers.begin() + index);
    
}

std::size_t PersonAllocator::getSize() const
{
    return this->readers.size();
}

Person* PersonAllocator::operator[](std::size_t index)
{
    return this->readers[index];
}