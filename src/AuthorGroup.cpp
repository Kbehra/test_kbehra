#include "AuthorGroup.h"

AuthorGroup::AuthorGroup(std::vector<std::string> names)
{
    for (auto name : names)
    {
        authorGroup.push_back(new Author(name));
    }
}


bool AuthorGroup::IsAuthor(std::string name)
{
    for (auto author : authorGroup)
    {
        if (author->IsAuthor(name)){return true;}
    }
    return false;
}


std::string AuthorGroup::GetAuthorName()
{
    std::string out;
    for (auto author : authorGroup)
    {
        out += author->GetAuthorName() + ';';
    }
    return out;
}