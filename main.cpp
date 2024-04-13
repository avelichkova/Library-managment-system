// #include "ISBN.hpp"

#include "Commands.hpp"
#include "SingletonCommands.hpp"
#include <fstream>

int main(int argc, char** argv)
{
    // ISBN a("256-PK-8");
    // ISBN b("23-PK-8");

    // std::cout << a.getISBN() << '\n';
    // std::cout << b.getISBN() << '\n';


    // Person petya("Petya", 233);
    // ISBN b1("256-PK-8");
    // Book book1 (b1, "Kartofi", "Az");

    // PersonAllocator p;
    // BookAllocator book1;
    // ISBN b1("256-PK-8");
    // ISBN b2("25-PK-8");
    // Person* petya = p.allocate("Petya", 233);
    // Book* addBook1 = book1.allocate(b1, "Kartofi", "Az");
    // Book* addBook2 = book1.allocate(b1, "Kartofi1", "Az1");

    // petya->addBook(*addBook1);
    // petya->addBook(*addBook2);

    // petya->printBooks();

    if(argc == 2)
    {
        std::string path(argv[1]);
        SingletonCommands::getInstance().openExictingFile(path);
    }
    
    SingletonCommands::getInstance().start();
    // return 0;
}