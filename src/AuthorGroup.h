#ifndef TEST_KBEHRA_AUTHORGROUP_H
#define TEST_KBEHRA_AUTHORGROUP_H

#include <vector>

#include "IAuthor.h"
#include "Author.h"

///
/// Object to store a vector of Author (Group)
///
class AuthorGroup : public IAuthor
{

public :
    AuthorGroup(std::vector<std::string> names);

    ///
    /// \param name : the name of the author
    /// \return return true if we can find one author with the same name in
    /// the group
    bool IsAuthor(std::string name);

    /// return the list of authors name in the AuthorGroup
    /// \param out
    /// \return
    std::string GetAuthorName();


private :
    std::vector<Author*>  authorGroup;
};


#endif //TEST_KBEHRA_AUTHORGROUP_H
