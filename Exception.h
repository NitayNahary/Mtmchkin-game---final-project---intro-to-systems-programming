
#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H
#include <string>

// The base class for exceptions
//static const char* DECK_NOT_FOUND ="";
class exception {
public:
    virtual ~exception() = default;
    virtual const char* what() const = 0;
};

// deck file not found exception
class DeckFileNotFound : public exception {
    const char* what() const override{
        return "Deck File Error: File not found";
    }
};

// Format error in deck file exception
// Returns the line number
class DeckFileFormatError : public exception {
    int m_lineNumber;
public:
    DeckFileFormatError(int lineNumber) : m_lineNumber(lineNumber){}
    const char* what() const override{
        std::string result = "Deck File Error: File format error in line " + std::to_string(m_lineNumber);
        return result.c_str();
    }
};

// Invalid size of deck file exception
class DeckFileInvalidSize : public exception {
    const char* what() const override{
        return "Deck File Error: Deck size is invalid";
    }
};

// Invalid name exception
class InvalidName : public exception{
    const char* what() const override{
        return "Invalid Name";
    }
};

// End of file exception
class EndOfFile : public exception{
    const char* what() const override{
        return "End Of File";
    }
};

// General error exception
class GeneralError : public exception{
    const char* what() const override{
        return "Reason Unknown";
    }
};

// Invalid team players input exception
class InvalidTeamInput : public exception{
    const char* what() const override{
        return "Invalid team players input";
    }
};

#endif //HW4_EXCEPTION_H
