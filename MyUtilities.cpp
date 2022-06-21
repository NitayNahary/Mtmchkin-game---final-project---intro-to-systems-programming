
#include "MyUtilities.h"
using std::string;
#define FAIL_BUFFER 256



void getIntInputNumber(int& dest, int startOfRange, int endOfRange, void invalidError()){
    std::string input;
    int inputAsInt;
    bool inRange = false;
    do {
        std::getline(std::cin, input);
        //std::cerr << "1: " << input << std::endl;
        while (std::cin.fail() || input.find_first_not_of("0123456789") != std::string::npos) {
            if(std::cin.eof()){
                throw EndOfFile();
            }
            invalidError();
            std::cin.clear();
            //std::cin.ignore(FAIL_BUFFER, '\n');
            std::getline(std::cin, input);
           // std::cerr << "2: " << input << std::endl;
        }
        std::string::size_type st;
        inputAsInt = std::stoi(input, &st);
        if( inputAsInt < startOfRange || inputAsInt > endOfRange){
            inRange = true;
        }else{
            invalidError();
        }
    } while (!inRange);
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