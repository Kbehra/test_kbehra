#ifndef TEST_KBEHRA_AUTHORCOLLECTION_H
#define TEST_KBEHRA_AUTHORCOLLECTION_H

#include <vector>

#include "Author.h"
#include "LibraryContents/ILibraryContent.h"

///
/// Describe all the library content writen by an IAuthor (single or multiple Author)
///
class AuthorCollection
{
public :
    /// default constructor
    AuthorCollection() {};

    /// constructor with an element
    AuthorCollection(ILibraryContent* firstContent);

    /// Add a library content on the collection of an IAuthor
    /// \param element
    void AddElement(ILibraryContent* element);

    /// Get a reference on the specific content by its index in the collection
    /// \param index
    /// \return
    ILibraryContent* GetElement(int index);

    ///
    /// \param title : the name of the content that we are looking for
    /// \return : index of the content in the collection, -1 if the content is not in the collection
    int GetIndexInCollection(std::string title);

    ///
    /// \param title
    /// \return return true if the given name is in a collection, false otherwise
    bool DoesBelongTo(std::string title);

    /// return the number of element of a collection for an IAuthor
    /// \return
    int GetCollectionSize();

private:
    std::vector<ILibraryContent*> authorCollection;
};


#endif //TEST_KBEHRA_AUTHORCOLLECTION_H
