#ifndef TEST_KBEHRA_NOVEL_H
#define TEST_KBEHRA_NOVEL_H

#include "ILibraryContent.h"
#include "Book.h"

///
///  Object to implement a novel structure
///
class Novel : public Book
{
public:
    Novel(std::string title, IAuthor* author);
    void PrintContentData();
};

#endif //TEST_KBEHRA_NOVEL_H
