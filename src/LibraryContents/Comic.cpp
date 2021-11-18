#include "Comic.h"


Comic::Comic(std::string title, IAuthor *author) : Book(title, author)
{
    this->type = ContentType::LibraryContentType::Comic;
}


void Comic ::PrintContentData()
{
    std::cout << "title : " << title << std::endl;
    std::cout << "Category  : " <<  "Comic " << std::endl;
    std::cout << "author name : " ;
    std::cout << *author << std::endl;
}