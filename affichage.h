#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include "books.h"

void printArgumentShow();
void getUserInput(char* userInput);
void interactionWithTheUser(bool* inloop, char value, Library* library);
void returnInteraction(bool* inloop, struct Books *book, unsigned int numBooks);

#endif // AFFICHAGE_H_INCLUDED
