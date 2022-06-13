
#include "MyUtilities.h"
using std::string;
#define FAIL_BUFFER 256



void getIntInputNumber(int& dest, int startOfRange, int endOfRange, void invalidError()){
    std::string input;
    int inputAsInt;
    do {
        std::getline(std::cin, input);
        while (std::cin.fail() || input.find_first_not_of("0123456789") != std::string::npos) {
            if(std::cin.eof()){
                throw EndOfFile();
            }
            invalidError();

            if (input.find_first_not_of("0123456789") == std::string::npos) {
                std::cin.clear();
                std::cin.ignore(FAIL_BUFFER, '\n');
            }
            std::getline(std::cin, input);
        }
        std::string::size_type st;
        inputAsInt = std::stoi(input, &st);
    } while (inputAsInt < startOfRange || inputAsInt > endOfRange);
    dest = inputAsInt;
}
void getStringInput(string& dest, void invalidError()){
    string theInput;
    std::getline(std::cin, theInput);
    while(std::cin.fail()) {
        if(std::cin.eof()){
            throw EndOfFile();
        }
        invalidError();
        std::cin.clear();
        std::cin.ignore(FAIL_BUFFER, '\n');
        std::getline(std::cin, theInput);
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