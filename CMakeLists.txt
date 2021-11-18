cmake_minimum_required(VERSION 3.00)

set(PROJECT_NAME "TEST_KBEHRA")
set(PROJECT_SOURCE_DIR  "./src/")

project(${PROJECT_NAME})

set (CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Library.cpp
        src/Library.h
        src/LibraryContents/ILibraryContent.h
        src/Author.h
        src/AuthorCollection.h
        src/LibraryContents/Book.h
        src/IAuthor.h
        src/AuthorGroup.h
        src/LibraryContents/Comic.h
        src/LibraryContents/Novel.h
        src/LibraryContents/Movie.h
        src/LibraryContents/Book.cpp
        src/LibraryContents/Comic.cpp
        src/LibraryContents/Novel.cpp
        src/AuthorCollection.cpp
        src/AuthorGroup.cpp
        src/Author.cpp)