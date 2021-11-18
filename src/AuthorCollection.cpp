#include "AuthorCollection.h"

AuthorCollection::AuthorCollection(ILibraryContent *firstContent)
{
    authorCollection.push_back(firstContent);
}


void AuthorCollection::AddElement(ILibraryContent *element)
{
    authorCollection.push_back(element);
}


ILibraryContent* AuthorCollection::GetElement(int index)
{
    return authorCollection.at(index);
}


int AuthorCollection::GetIndexInCollection(std::string title)
{
    for (int i = 0; i < authorCollection.size(); i++)
    {
        if (authorCollection[i]->IsTitleEqual(title)){return i;}
    }
    return -1;
}


bool AuthorCollection::DoesBelongTo(std::string title)
{
    for (auto content : authorCollection)
    {
        if (content->IsTitleEqual(title)){return true;}
    }
    return false;
}

int AuthorCollection::GetCollectionSize()
{
    return authorCollection.size();
}
