
#ifndef MY_UTIL_H
#define MY_UTIL_H


#include <limits.h>
#include "utilities.h"
#include "Exception.h"

#define BUFFER_SIZE 256
#define MAX_NAME_LENGTH 15


/* ---------------------------------------------------------------------------------------------- */

/*
*  Get a int input number between start and end of a specific range
*   @param
*           dest - a reference to the input parameter
*           startOfRange - the min value of the input
*           EndOfRange - the max value of the input
*           void function pointer with no param - invalid input print message
*
*  @return
*          int - number of rounds played
*/
void getIntInputNumber(int& dest, int startOfRange = -INT_MAX, int endOfRange = INT_MAX , void invalidError() = printInvalidInput);

/*
*  Get a string input number between start and end of a specific range
*   @param
*           dest - a reference to the input parameter
*           void function pointer with no param - invalid input print message
*
*  @return
*          int - number of rounds played
*/
void getStringInput(std::string& dest, void invalidError() = printInvalidInput);

/*
*  Check if a name is a valid name
*   @param
*           name - a name
*
*  @return
*          bool - true/false
*/
bool isValidName(const std::string& name);

// prints team errors
void printTeamErrors();

#endif //MY_UTIL_H