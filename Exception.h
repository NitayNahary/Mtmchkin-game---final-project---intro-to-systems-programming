
#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H
#include <string>

// The base class for exceptions
class exception {
public:
    virtual ~exception() = default;
    virtual std::string what() const = 0;
};

// deck file not found exception
class DeckFileNotFound : public exception {
    std::string what() const override{
        return "Deck File Error: File not found";
    }
};

// Format error in deck file exception
// Returns the line number
class DeckFileFormatError : public exception {
    int m_lineNumber;
public:
    DeckFileFormatError(int lineNumber) : m_lineNumber(lineNumber){}
    std::string what() const override{
        char outPut[200] = {'\0'};
        sprintf(outPut, "Deck File Error: File format error in line %d", m_lineNumber);
        return outPut;
    }
};

// Invalid size of deck file exception
class DeckFileInvalidSize : public exception {
    std::string what() const override{
        return "Deck File Error: Deck size is invalid";
    }
};

// Invalid name exception
class InvalidName : public exception{
    std::string what() const override{
        return "Invalid Name";
    }
};

// End of file exception
class EndOfFile : public exception{
    std::string what() const override{
        return "End Of File";
    }
};

// General error exception
class GeneralError : public exception{
    std::string what() const override{
        return "Reason Unknown";
    }
};

// Invalid team players input exception
class InvalidTeamInput : public exception{
    std::string what() const override{
        return "Invalid team players input";
    }
};

#endif //HW4_EXCEPTION_H
