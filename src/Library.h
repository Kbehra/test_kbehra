#ifndef TEST_KBEHRA_LIBRARY_H
#define TEST_KBEHRA_LIBRARY_H

#include <iostream>
#include <vector>

#include "AuthorCollection.h"
#include "IAuthor.h"

class Library
{
public :
    /// default construct
    Library() = default;

    /// Add a book element in the Library collection
    /// the book is added if, it is not already in the collection of an author
    /// if an author doesn't exists in the collection, we create an AuthorCollection
    /// \param title : name of the content
    /// \param authorName : name of the author
    /// \param type  : category of the content
    void AddBook(std::string title, std::string authorName, ContentType::LibraryContentType type);

    /// Add a book element in the Library collection, with multiple authors.
    /// the book is added if, it is not already in the collection of an author
    /// if an author doesn't exists in the collection, we create an AuthorCollection
    /// \param title  : name of the content
    /// \param authorNames : names of authors
    /// \param type : category of the content
    void AddBook(std::string title, std::vector<std::string> authorNames, ContentType::LibraryContentType type);

    /// Add an author into the Library collection
    /// \param authorName
    void AddAuthor(std::string authorName);

    /// Search authors according to the title of a content
    /// if multiple content shared the same title, all contents will be displayed
    /// \param title  : title of the content
    void SearchAuthorsByTitle(std::string title);

    /// list all the content in the library collection of an author
    /// \param name : lastname of the author
    void SearchBookFromAuthor(std::string name);

private  :
    std::vector<std::pair<IAuthor*, AuthorCollection*>> collection;
    AuthorCollection* GetAuthorCollectionFromName(std::string name);

    /// Create a book that can be put into the Library
    /// \param type : the category of the book
    /// \param title : the title of the book
    /// \param authorCandidate : author(s) of this book
    /// \return
    ILibraryContent* CreateBook(ContentType::LibraryContentType type, std::string title, IAuthor* authorCandidate);

    /// Display info in console if a book is added in a collection or not
    static void DisplayConsoleInfo(std::string title, std::string authorName, ContentType::LibraryContentType type, bool state);
};


#endif //TEST_KBEHRA_LIBRARY_H
