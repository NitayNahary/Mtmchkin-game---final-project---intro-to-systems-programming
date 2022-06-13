
#ifndef MY_UTIL_H
#define MY_UTIL_H


#include <limits>
#include "utilities.h"
#include "Exception.h"

#define BUFFER_SIZE 256
#define MAX_NAME_LENGTH 15


/* ---------------------------------------------------------------------------------------------- */

void getIntInputNumber(int& dest, int startOfRange = -INT_MAX, int endOfRange = INT_MAX , void invalidError() = printInvalidInput);

void getStringInput(std::string& dest, void invalidError() = printInvalidInput);

bool isValidName(const std::string& name);

#endif //MY_UTIL_H