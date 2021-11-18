#include "Author.h"

Author::Author(std::string name)
{
    lastName = name;
}


bool Author::IsAuthor(std::string name)
{
    return name == lastName;
}


std::string Author::GetAuthorName()
{
    return lastName;
}