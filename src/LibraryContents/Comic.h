#ifndef TEST_KBEHRA_COMIC_H
#define TEST_KBEHRA_COMIC_H
#include <iostream>

#include "ILibraryContent.h"
#include "../IAuthor.h"
#include "Book.h"

///
/// Object to implement a Comic structure
///
class Comic : public Book
{
public :
    Comic(std::string title, IAuthor* author);
    void PrintContentData();

private :
    // some private field, that may be different
    // of a book
    IAuthor* drawer;
};

#endif //TEST_KBEHRA_COMIC_H
