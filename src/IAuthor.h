#ifndef TEST_KBEHRA_IAUTHOR_H
#define TEST_KBEHRA_IAUTHOR_H
#include <iostream>

#include <string>

///
/// Interface for an Author of a library Content
///
class IAuthor
{
public:
    virtual bool IsAuthor(std::string name) = 0;
    virtual std::string GetAuthorName() = 0;
};

std::ostream&operator<<(std::ostream& os, IAuthor& a);

#endif //TEST_KBEHRA_IAUTHOR_H
