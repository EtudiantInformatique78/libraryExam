#ifndef USERINTERACTION_H_INCLUDED
#define USERINTERACTION_H_INCLUDED
#include "books.h"

void filterAuthorBooks(struct Books *book, int numBooks, char* input);
void filterTitleBooks(struct Books *book, int numBooks, char* input);
void filterYearBooks(struct Books *book, int numBooks, int input);
void searchAuthor(struct Books *book, int numBooks);
void searchTitle(struct Books *book, int numBooks);
void searchYear(struct Books *book, int numBooks);

#endif // USERINTERACTION_H_INCLUDED
