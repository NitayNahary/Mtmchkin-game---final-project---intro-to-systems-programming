
#include "MyUtilities.h"

using std::string;




void getIntInputNumber(int& dest, int startOfRange, int endOfRange, void invalidError()){
    std::string theInput;
    int inputAsInt;
    do {
        std::getline(std::cin, theInput);

        while (std::cin.fail() || std::cin.eof() || theInput.find_first_not_of("0123456789") != std::string::npos) {
            if(std::cin.eof()){
                throw EndOfFile();
            }
            invalidError();

            if (theInput.find_first_not_of("0123456789") == std::string::npos) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
            }

            std::getline(std::cin, theInput);
        }
        std::string::size_type st;
        inputAsInt = std::stoi(theInput, &st);
    } while (inputAsInt < startOfRange || inputAsInt > endOfRange);
    dest = inputAsInt;
}
void getStringInput(string& dest, void invalidError()){
    string theInput;
    std::getline(std::cin, theInput);
    while(std::cin.fail()) {
        std::cin.clear();
        std::getline(std::cin, theInput);
        if(std::cin.eof()){
            throw EndOfFile();
        }
        invalidError();
    }
    dest = theInput;
}
bool isValidName(const std::string& name){
    if(name.size() > MAX_NAME_LENGTH){
        return false;
    }
    for(char letter : name){
        if(letter < 'A' || (letter > 'Z' && letter <'a') || letter > 'z'){
            return false;
        }
    }
    return true;
}