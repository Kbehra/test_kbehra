#ifndef TEST_KBEHRA_AUTHOR_H
#define TEST_KBEHRA_AUTHOR_H

#include <string>

#include "IAuthor.h"

///
/// Describe an Author for a library content
///
class Author : public IAuthor
{
public:
    Author(std::string name);

    ///
    /// \param name
    /// \return true if the given name equal to the lastName of the author
    bool IsAuthor(std::string name);

    /// Return the name (lastname) of the author
    /// \return
    std::string GetAuthorName();

private:
    std::string lastName;
};


#endif //TEST_SOGITECH_KBEHRA_AUTHOR_H
