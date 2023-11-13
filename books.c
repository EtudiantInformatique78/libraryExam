#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "books.h"
#define MAXCHAR 1000

void printHeaderOfBookDatabase()
{

    printf("-------------------------------------------------------------\n");
    printf("|   id   |        Title       |       Author       |  Year  |\n");
    printf("-------------------------------------------------------------\n");
}


void showBook(struct Books *book, StateBook value)
{
    if(book != NULL)
    {
        if (book->state == value)
        {
            printf("|  %3d   |%20s|%20s|  %4d  |\n", book->id, book->title, book->author, book->publicationYear);
            printf("-------------------------------------------------------------\n");
        }

    }
    else
    {
        printf("No book on the library\n");
    }

}



void showBooks(struct Books *book, unsigned int numberOfBook, StateBook enumValue)
{
    printHeaderOfBookDatabase();
    for(unsigned int i =0; i < numberOfBook; i++)
    {
        showBook(book+i, enumValue);
    }
}

void initializeLibrary(Library* library)
{
    library->lstBook = (Books*) malloc(50 * sizeof(Books));
    library->nbBook = 0;

    ///////////////////////
    FILE *fp = NULL;
    char row[MAXCHAR];
    char *token = NULL;

    fp = fopen("books.csv","r");

    bool firstLine = true;

    int i = 0;

    while (feof(fp) != true)
    {
        if(!firstLine)
        {
            (library->lstBook)[i].id = i;



            fgets(row, MAXCHAR, fp);
            printf("Row: %s", row);


            token = strtok(row, ",");
            sprintf((library->lstBook)[i].title, "%s", token);

            token = strtok(row, ",");
            sprintf((library->lstBook)[i].author, "%s", token);

            (library->lstBook)[i].state = AVAILABLE;
            (library->lstBook)[i].remainingDays = 0;


            // Do not use rand() function for security !
            int r = (rand() % 2023) + 1;
            (library->lstBook)[i].publicationYear = r;
            /*
            while(token != NULL)
            {
                printf("Token: %s\n", token);
                token = strtok(NULL, ",");
            }
            */

        }
        else
        {
            fgets(row, MAXCHAR, fp);
            //printf("Row: %s", row);
            firstLine = false;
        }
    }

    fclose(fp);
    ///////////////////////////////////////////

    for(int i = 0; i < 50; i++)
    {
        (library->lstBook)[i].id = i;
        sprintf((library->lstBook)[i].title, "Title_%d", i);
        sprintf((library->lstBook)[i].author, "Author_%d", i);
        (library->lstBook)[i].state = AVAILABLE;
        (library->lstBook)[i].remainingDays = 0;

        // Do not use rand() function for security !
        int r = (rand() % 2023) + 1;
        (library->lstBook)[i].publicationYear = r;

        library->nbBook+=1;

    }
}

void freeLibrary(Library* library)
{
    free(library->lstBook);
}


Books* addBooks(Books* books, unsigned int *totalBooks)
{
    unsigned int numBook = *totalBooks;
    books = (Books*) realloc( books  ,(numBook+1) * sizeof(Books));
    if(numBook == 0)
    {
        books[numBook].id = 0;
    }
    else
    {
        int lastId = books[numBook-1].id;
        books[numBook].id = lastId+1;
    }

    char userInput[20] = {0};
    printf("Title : ");

    if(scanf("%s", userInput) == 0)
    {
        printf("No title\n");
    }
    strcpy(books[numBook].title, userInput);

    printf("Author : ");
    if(scanf("%s", books[numBook].author) == 0)
    {
        printf("No author\n");
    }

    printf("Publication Year : ");
    if(scanf("%d", &books[numBook].publicationYear) == 0)
    {
        printf("No year of publication\n");
    }

    books[numBook].state = AVAILABLE;
    books[numBook].remainingDays = 0;

    //showBook(&books[numBook]);
    (*totalBooks)++;

    return books;

    printf("Book added successfully !\n");
}

void rentBook(struct Books *books, unsigned int totalBooks, unsigned int indexALouer)
{
    if (indexALouer >= 0 && indexALouer < totalBooks)
    {

        if (books[indexALouer].state == BORROWED)
        {
            printf("This book is not available to be borrowed right now.\n");
        }
        else
        {
            books[indexALouer].state = BORROWED;
            books[indexALouer].remainingDays = 7;
            printf("The book \"%s\" has been rent successfully for %d days.\n", books[indexALouer].title, books[indexALouer].remainingDays);
        }
    }
    else
    {
        printf("There is no book named like that.\n");
    }
}

void returnBook(struct Books *books, unsigned int totalBooks, unsigned int indexALouer)
{
    if (indexALouer >= 0 && indexALouer < totalBooks)
    {

        if (books[indexALouer].state == AVAILABLE)
        {
            //color(12,0);
            printf("This book is already available right now.\n");
            //color(15,0);
        }
        else
        {
            books[indexALouer].state = AVAILABLE;
            books[indexALouer].remainingDays = 0;
            //color(2,0);
            printf("The book \"%s\" has been return successfully.\n", books[indexALouer].title);
            //color(15,0);
        }
    }
    else
    {
        //color(12,0);
        printf("There is no book named like that.\n");
        //color(15,0);
    }
}
