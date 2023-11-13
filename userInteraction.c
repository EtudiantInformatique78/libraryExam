#include <stdio.h>

#include "compare.h"
#include "books.h"


void filterAuthorBooks(struct Books *book, int numBooks, char* input)
{
    printHeaderOfBookDatabase();
    for(int i=0; i < numBooks; i++)
    {
        if(compare_string((book + i)->author, input))
        {
            showBook(book + i, AVAILABLE);
        }
    }
}

void filterTitleBooks(struct Books *book, int numBooks, char* input)
{
    printHeaderOfBookDatabase();
    for(int i=0; i < numBooks; i++)
    {
        if(compare_string((book + i)->title, input))
        {
            showBook(book + i, AVAILABLE);
        }
    }
}

void filterYearBooks(struct Books *book, int numBooks, int input)
{
    printHeaderOfBookDatabase();
    for(int i = 0; i < numBooks; i++)
    {
        if(compare_int( (book+i)->publicationYear, input  ))
        {
            showBook(book+i, AVAILABLE);
        }
    }
}

void searchAuthor(struct Books *book, int numBooks)
{
    char message[] = "Enter the first letter of the author : ";
    char userInput[20] = {0};

    printf("%s", message);
    scanf("%s", userInput);

    printf("%s\n", userInput);

    filterAuthorBooks(book, numBooks, userInput);
}

void searchTitle(struct Books *book, int numBooks)
{
    char message[] = "Enter the first letter of the title : ";
    char userInput[20] = {0};

    printf("%s", message);
    scanf("%s", userInput);

    printf("%s\n", userInput);

    filterTitleBooks(book, numBooks, userInput);
}

void searchYear(struct Books *book, int numBooks)
{
    char message[] = "Enter the first digits of the year : ";
    int year = 1;

    printf("%s", message);
    scanf("%d", &year);

    filterYearBooks(book, numBooks, year);

    //printf("Not implemented\n");
}
