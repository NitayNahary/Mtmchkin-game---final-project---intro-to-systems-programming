
#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H
#include <string>
class exception {
public:
    virtual ~exception() = default;
    virtual std::string what() const = 0;
};

class DeckFileNotFound : public exception {
    std::string what() const override{
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public exception {
    int m_lineNumber;
    std::string m_badInput;
public:
    DeckFileFormatError(int lineNumber, std::string badInput) : m_lineNumber(lineNumber), m_badInput(badInput){}
    std::string what() const override{
        char outPut[200] = {'\0'};
        sprintf(outPut, "Deck File Error: File format error in line %d", m_lineNumber);
        return outPut;
    }
};
class DeckFileInvalidSize : public exception {
    std::string what() const override{
        return "Deck File Error: Deck size is invalid";
    }
};

class InvalidName : public exception{
    std::string what() const override{
        return "Invalid Name";
    }
};

class EndOfFile : public exception{
    std::string what() const override{
        return "End Of File";
    }
};

#endif //HW4_EXCEPTION_H
