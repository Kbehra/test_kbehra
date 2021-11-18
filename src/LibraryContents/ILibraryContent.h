#ifndef TEST_KBEHRA_ILIBRARYCONTENT_H
#define TEST_KBEHRA_ILIBRARYCONTENT_H

#include <string>

namespace  ContentType
{
    ///
    /// enum of available contents type in the library
    ///
    enum LibraryContentType
    {
        Comic = 0,
        Novel = 1
    };
}

///
/// Interface to describe content that can be found in the
/// Library. It can be a Book, a Comic , ...
///
class ILibraryContent
{
public :
    ~ILibraryContent() = default;
    virtual void PrintContentData() = 0;
    virtual bool IsTitleEqual(std::string title) = 0;
};


#endif //TEST_KBEHRA_ILIBRARYCONTENT_H
