
#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H

#include <string>
#include <iostream>
#include <cstring>
#include <exception>

// Base class Exception inherits from std::exception
class Exception : public std::exception{
public:
    virtual ~Exception() override = default;
    virtual const char* what() const noexcept override{
        return "An Error Has Occurred";
    }
};

// deck file not found exception
class DeckFileNotFound : public Exception {
    const char* what() const noexcept override{
        return "Deck File Error: File not found";
    }
};

// Format error in deck file exception
// Returns the line number
class DeckFileFormatError : public Exception {
    static const int BUFFER_SIZE = 64;
    int m_lineNumber;
    char m_result[BUFFER_SIZE];
public:
    explicit DeckFileFormatError(int lineNumber) : m_lineNumber(lineNumber), m_result(){
        for(int i = 0; i<BUFFER_SIZE; i++){
            m_result[i] = '\0';
        }
        strcat(m_result,"Deck File Error: File format error in line ");
        sprintf(m_result + strlen(m_result), "%d", m_lineNumber);
    }
    const char* what() const noexcept override {
        return m_result;
    }
};

// Invalid size of deck file exception
class DeckFileInvalidSize : public Exception {
    const char* what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }
};

// Invalid name exception
class InvalidName : public Exception{
    const char* what() const noexcept override{
        return "Invalid Name";
    }
};

// End of file exception
class EndOfFile : public Exception{
    const char* what() const noexcept override{
        return "End Of File";
    }
};

// General error exception
class GeneralError : public Exception{
    const char* what() const noexcept override{
        return "Reason Unknown";
    }
};

// Invalid team players input exception
class InvalidTeamInput : public Exception{
    const char* what() const noexcept override{
        return "Invalid team players input";
    }
};

#endif //HW4_EXCEPTION_H
