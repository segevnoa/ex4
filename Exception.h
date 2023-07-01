#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

/* ---------------------------------------------------------------------------------------------- */
// ------------------------------------- File Exceptions ---------------------------------------- //

class DeckFileNotFound : public std::exception{
public:
    //-- fields --//
    std::string m_exception = "Deck File Error: File not found";

    //-- methods --//
    DeckFileNotFound() = default;
    const char* what() const noexcept override {
        return m_exception.c_str();
    }
};

class DeckFileFormatError : public std::exception{
public:
    //-- fields --//
    int m_line;
    std::string m_error = "Deck File Error: File format error in line ";

    //-- methods --//
    DeckFileFormatError(int givenLine): m_line(givenLine){
        m_error = m_error + std::to_string(m_line);
    }
    const char* what() const noexcept override {
        return m_error.c_str();
    }
};

class DeckFileInvalidSize : public std::exception{
public:
    //-- fields --//
    std::string m_exception = "Deck File Error: Deck size is invalid";
    //-- methods --//
    DeckFileInvalidSize() = default;
    const char* what() const noexcept override {
        return m_exception.c_str();
    }
};

#endif //EXCEPTION_H
