#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Library.h"

/// implementation of the operator
std::ostream&operator<<(std::ostream& os, IAuthor& a)
{
    os << a.GetAuthorName();
    return os;
};


static void DisplayHelpMessage()
{
    std::cout << "Hello World !\n" << std::endl;
    std::cout <<
              "0 : exit the application \n\n"
              "1 : add a book on the library \n"
              "    ex add a novel: 1 \"@nameOfTheNovel\" \"@nameOfTheAuthor\" 0 \n"
              "    ex add a comic: 1 \"@nameOfTheComic\" \"@nameOfTheAuthor\" 1 \n\n"
              "2 : add an author on the library \n"
              "    ex : 2 \"@nameOfTheAuthor\"\n\n"
              "3 : search for an author with a title \n"
              "    ex : 3 \"@theTitleToSearch\"\n\n"
              "4 : search all content for a given author \n"
              "    ex : 4 \"@theAuthorToSeachForContent\"\n\n"
              "5 : add some samples on the library\n\n"
              "6 : help, display this message\n"
              "" << std::endl;
}

void ParseCmd(std::string userCmd, int& userOptionTarget,std::string& contentTitle, std::string& authorName,  ContentType::LibraryContentType& type);

int main(int argc, const char* argv[])
{
    DisplayHelpMessage();

    // init the library
    Library* l = new Library();

    while(true)
    {
        std::string userCmd = "";
        std::cout << "Please Enter a command : ";
        std::getline(std::cin, userCmd);

        int userOptionTarget = -1;
        std::string authorName = "";
        std::string contentTitle = "";
        ContentType::LibraryContentType type;

        ParseCmd(userCmd, userOptionTarget, contentTitle, authorName, type);

        // apply command
        switch (userOptionTarget)
        {
            case 0: return 0;
            case 1 :
                contentTitle.erase(std::remove(contentTitle.begin(), contentTitle.end(), '\"'), contentTitle.end());
                authorName.erase(std::remove(authorName.begin(), authorName.end(), '\"'), authorName.end());

                l->AddBook(contentTitle, authorName, type);
                break;
            case 2 :
                authorName.erase(std::remove(authorName.begin(), authorName.end(), '\"'), authorName.end());
                l->AddAuthor(authorName);
                break;
            case 3 :
                contentTitle.erase(std::remove(contentTitle.begin(), contentTitle.end(), '\"'), contentTitle.end());
                authorName.erase(std::remove(authorName.begin(), authorName.end(), '\"'), authorName.end());
                l->SearchAuthorsByTitle(contentTitle);
                break;
            case 4 :
                authorName.erase(std::remove(authorName.begin(), authorName.end(), '\"'), authorName.end());
                l->SearchBookFromAuthor(authorName);
                break;
            case 5 :
                // add some elements on lib
                l->AddBook("La nuit des temps", "Barjavel", ContentType::LibraryContentType::Novel);
                l->AddBook("Ravage", "Barjavel", ContentType::LibraryContentType::Novel);
                l->AddBook("Le retour des ténèbres", std::vector<std::string>{"Asimov", "Silverberg"}, ContentType::LibraryContentType::Novel);
                l->AddBook("Face aux feux du soleil", "Asimov", ContentType::LibraryContentType::Novel);
                l->AddAuthor("Dupont");
                l->AddBook("Un exemple de livre", "Dupont", ContentType::LibraryContentType::Novel);
                l->AddBook("Un exemple de BD", "Dupont", ContentType::LibraryContentType::Comic);


            default:
                break;
        }
    }
    return 0;
}

void ParseCmd(std::string userCmd, int& userOptionTarget,std::string& contentTitle, std::string& authorName,  ContentType::LibraryContentType& type)
{
    std::istringstream cmd (userCmd);
    int arg = 0;
    bool isSubstring = false;
    for (std::string line ; std::getline(cmd, line, ' ');)
    {
        int numberOfDelimiter = std::count(line.begin(), line.end(), '\"');

        if ((numberOfDelimiter || isSubstring) && arg > 0)
        {

            if (numberOfDelimiter && isSubstring)
            {
                if (arg == 1 && (userOptionTarget == 1 || userOptionTarget == 3)) {contentTitle += line;}
                if ((arg == 2 && userOptionTarget == 1 )|| arg == 1 && (userOptionTarget == 2 || userOptionTarget == 4)) {authorName += line;}

                arg++;
                isSubstring = false;
            }

            else if ((numberOfDelimiter && !isSubstring) || (!numberOfDelimiter && isSubstring))
            {
                if (arg == 1 && (userOptionTarget == 1 || userOptionTarget == 3)) {contentTitle += line + ' ';}
                if ((arg == 2 && userOptionTarget == 1 )|| arg == 1 && (userOptionTarget == 2 || userOptionTarget == 4)) {authorName += line;}

                isSubstring = numberOfDelimiter == 2 ? false : true;
                if(!isSubstring){arg++;}
            }
        }
        else
        {
            // get the number of the command
            try
            {
                if (arg == 0)
                {
                    userOptionTarget = std::stoi(line);
                }
                if (arg == 3)
                {
                    type = std::stoi(line) == 0 ? ContentType::LibraryContentType::Novel : ContentType::LibraryContentType::Comic;
                }
            }
            catch(std::invalid_argument)
            {
                std::cout << "invalid command" << std::endl;
                //return;
            }

            switch (userOptionTarget)
            {
                case 0: return;
                case 1 :
                    if (arg == 1) {contentTitle = line;}
                    if (arg == 2) {authorName = line;}
                    break;
                case 2 :
                    if (arg == 1) {authorName = line;}
                    break;
                case 3 :
                    if (arg == 1) {contentTitle = line;}
                    break;
                case 4 :
                    if (arg == 1) {authorName = line;}
                    break;
                case 5 :
                    break;
                case 6 :
                    DisplayHelpMessage();
                    break;
                default:
                    std:: cout << "invalid command" << std::endl;
                    break;
            }
            arg++;
        }
    }
}


