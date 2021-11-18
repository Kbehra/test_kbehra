#include "Library.h"
#include "LibraryContents/Book.h"
#include "LibraryContents/Novel.h"
#include "LibraryContents/Comic.h"
#include "Author.h"
#include "AuthorGroup.h"

void Library::AddBook(std::string title, std::string authorName, ContentType::LibraryContentType type)
{
    IAuthor* authorCandidate = new Author(authorName);
    AuthorCollection* authorCollection = GetAuthorCollectionFromName(authorName);

    ILibraryContent* book = CreateBook(type, title, authorCandidate);

    if (book == nullptr) { return;  }

    bool isAdded = false;

    if (authorCollection == nullptr)
    {
        // this is a new author, so we create a new authorCollection for him
        // and we add the book in the collection
        authorCollection = new AuthorCollection(book);
        this->collection.push_back(std::make_pair(authorCandidate, authorCollection));
        isAdded = true;
    }
    else
    {
        // the author already exists on collection
        if(!authorCollection->DoesBelongTo(title))
        {
            authorCollection->AddElement(book);
            isAdded = true;
        }
    }
    DisplayConsoleInfo(title, authorName, type, isAdded);
}


void Library::AddBook(std::string title, std::vector<std::string> authorsName, ContentType::LibraryContentType type)
{
    IAuthor* authorGroup = new AuthorGroup(authorsName);

    ILibraryContent* book = CreateBook(type, title, authorGroup);
    if (book == nullptr) { return; }
    // search for the author collection of each author
    // add the book or create the collection and add the book
    for (auto authorName : authorsName)
    {
        AuthorCollection* authorCollection = GetAuthorCollectionFromName(authorName);
        IAuthor* authorCandidate = new Author(authorName);

        bool isAdded = false;

        if (authorCollection == nullptr)
        {
            // this is a new author, so we create a new authorCollection for him
            // and we add the book in the collection
            authorCollection = new AuthorCollection(book);
            this->collection.push_back(std::make_pair(authorCandidate, authorCollection));
            isAdded = true;
        }
        else
        {
            // the author already exists on collection
            if(!authorCollection->DoesBelongTo(title))
            {
                authorCollection->AddElement(book);
                isAdded = true;
            }
        }
        DisplayConsoleInfo(title, authorName, type, isAdded);
    }
}


void Library::AddAuthor(std::string authorName)
{
    IAuthor* authorCandidate = new Author(authorName);
    AuthorCollection* authorCollection = GetAuthorCollectionFromName(authorName);
    if (authorCollection == nullptr)
    {
        // this is a new author, so we create a new empty authorCollection for him
        authorCollection = new AuthorCollection();
        this->collection.push_back(std::make_pair(authorCandidate, authorCollection));
    }
    std::cout << "the author " << authorName << " was added to the library" << std::endl;
}


void Library::SearchAuthorsByTitle(std::string title)
{
    bool found = false;
    for(auto it = collection.begin(); it != collection.end(); ++it)
    {
        if(it->second->DoesBelongTo(title))
        {
            found = true;
            // we find one of the author of the content
            int index = it->second->GetIndexInCollection(title);
            if (index > -1)
            {
                // we get the real author (for the complet list)
                std::cout << *it->first << std::endl;
            }
        }
    }
    if(!found) {std::cout << "Author not found with the title  "<< title << std::endl;}
}


void Library::SearchBookFromAuthor(std::string name)
{
    bool found = false;
    for(auto it = collection.begin(); it != collection.end(); ++it)
    {
        if(it->first->IsAuthor(name))
        {
            for (int i = 0; i < it->second->GetCollectionSize(); i++)
            {
                found = true;
                it->second->GetElement(i)->PrintContentData();
            }
        }
    }
    if(!found){std::cout << "the given name " << name << " was not found in the author collection or there is no content for this author" << std::endl;}
}


AuthorCollection* Library::GetAuthorCollectionFromName(std::string name)
{
    for(auto it = collection.begin(); it != collection.end(); ++it)
    {
        if(it->first->IsAuthor(name))
        {
            return it->second;
        }
    }
    return nullptr;
}


ILibraryContent* Library::CreateBook(ContentType::LibraryContentType type, std::string title, IAuthor* authorCandidate)
{
    ILibraryContent* book = nullptr;

    // here we can construct elements for the library
    if (type == ContentType::LibraryContentType::Comic)
    {
        book = new Comic(title, authorCandidate);
    }
    else if (type == ContentType::LibraryContentType::Novel)
    {
        book = new Novel(title, authorCandidate);
    }

    if (book == nullptr) 
    {
        std::cout << "Inputs arguments were misinterpreted. Are you sure of your input command ?" << std::endl; 
    }
    return book;
};


void Library::DisplayConsoleInfo(std::string title, std::string authorName, ContentType::LibraryContentType type,
                                        bool state)
{
    if (state)
    {
        std::string printableType = type == ContentType::LibraryContentType::Novel ? "Novel" : "Comic";
        std::cout << "Book " << title << " written by " << authorName << " was added to the library in the category : "
                  << printableType << std::endl;
    }
    else
    {

        std::cout << "The book " << title << " is already in the collection of this author"<< std::endl;
    }
}
