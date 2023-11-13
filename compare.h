#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED
#include <stdbool.h>

bool compare_string(char* var1, char* var2);
int* intToListOfDigits(int integer);
void freeIntList(int * ptrInt);
int sizeOfInteger(int integer);
bool compare_int(int var1, int var2);

#endif // COMPARE_H_INCLUDED
