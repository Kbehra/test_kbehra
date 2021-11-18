#include "Novel.h"

Novel::Novel(std::string title, IAuthor* author) : Book(title, author)
{
    this->type = ContentType::LibraryContentType::Novel;
}

void Novel::PrintContentData()
{
    std::cout << "title : " << title << std::endl;
    std::cout << "Category  : " <<  "Novel " << std::endl;
    std::cout << "authors names : " ;
    std::cout << *author << std::endl;
}
