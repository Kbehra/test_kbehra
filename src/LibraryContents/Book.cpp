#include "Book.h"


Book :: Book(std::string title, IAuthor* author)
{
    this->title = title; this->author = author;
};


bool Book ::IsTitleEqual(std::string title)
{
    return title == this->title;
}

