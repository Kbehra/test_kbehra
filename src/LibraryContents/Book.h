#ifndef TEST_KBEHRA_BOOK_H
#define TEST_KBEHRA_BOOK_H
#include <iostream>

#include "ILibraryContent.h"
#include "../IAuthor.h"

class Book : public ILibraryContent
{
public :
    Book(std::string title, IAuthor* author);
    bool IsTitleEqual(std::string title);
    virtual void PrintContentData() = 0;

protected:
    ContentType::LibraryContentType type;
    std::string title;
    IAuthor* author;
};


#endif //TEST_KBEHRA_BOOK_H
