#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "books.h"
#include "compare.h"
#include "userInteraction.h"

void printArgumentShow()
{
    char show[] = "Hey ! Use [q] to quit, [l] to list books, [a] to add a book, [b] to book a book, [s] to search a book, [r] to return a book to the library or [d] to delete a book";
    printf("%s\n", show);

}

void getUserInput(char* userInput)
{
    printArgumentShow();
    int returnScanf = scanf("%1s", userInput);
    if(returnScanf > 1)
    {
        printf("More than one character in userInput\n");
    }
    else if(returnScanf == 0)
    {
        printf("No character\n");
    }
}


Books* addBookInteraction(struct Books *book, unsigned int *numBooks)
{
    // N'a pas rajouté le livre
    printf("addBooks ne rajoute pas le livre\n");

    char message[] = "Enter [a] to add a book or [q] to quit : ";
    printf("%s\n", message);

    char userInput[1];
    int returnScanf = scanf("%1s", userInput);
    if(returnScanf > 1)
    {
        printf("More than one character in userInput\n");
    }
    else if(returnScanf == 0)
    {
        printf("No character\n");
    }

    switch(userInput[0])
    {
        case 'a':
            book = addBooks(book, numBooks);
            //showBooks(book, numBooks);

            break;
        case 'q':
            break;
    }
    return book;
}

Books* deleteBooks(Books books[], unsigned int *totalBooks, unsigned int indexASupprimer)
{
    if (indexASupprimer >= 0 && indexASupprimer < *totalBooks)
    {
        for (int i = indexASupprimer; i < *totalBooks - 1; i++)
        {
            books[i] = books[i + 1];
            //books[i].id = i+1;
        }
        memset(&books[*totalBooks - 1], 0, sizeof(Books));

        (*totalBooks)--;

        // color(2,0);
        printf("Book deleted successfully!\n\n");
        // color(15,0);
    }
    else
    {
        // color(12,0);
        printf("This book doesn't exist in our library.\n\n");
        // color(15,0);
    }
    return books;
}

unsigned int idToIndex(struct Books *book, unsigned int* numBooks, unsigned int idIwant)
{
    // Binary search
    unsigned int low = 0;
    unsigned int high = *numBooks-1;
    while(low <= high)
    {
        unsigned int mid = (unsigned int) ((low+high)/2);
        if(book[mid].id < idIwant)
        {
            low = mid+1;
        }
        else if(book[mid].id > idIwant)
        {
            high = mid-1;
        }
        else
        {
            return book[mid].id;
        }
    }


    return 0;
}

Books* deleteBookInteraction(struct Books *book, unsigned int* numBooks)
{
    char output[] = "Do you want to delete a book ? if so, enter [d], if not enter [q] : ";
    printf("%s\n", output);

    char userInput[1];
    int returnScanf = scanf("%1s", userInput);
    if(returnScanf > 1)
    {
        printf("More than one character in userInput\n");
    }
    else if(returnScanf == 0)
    {
        printf("No character\n");
    }

    switch(userInput[0])
    {
        case 'd':
            // borrow book
            char output[] = "Enter the id of the book to delete, please: ";
            printf("%s\n", output);
            unsigned int idToDelete = 0;
            if (scanf("%u", &idToDelete))
            {
                printf("Line :%d\n", __LINE__ );
                printf("No index entered\n");
            }

            unsigned int indexToDelete = idToIndex(book, numBooks, idToDelete);


            book = deleteBooks(book, numBooks, indexToDelete);
            break;
        case 'q':
            break;
    }
    return book;
}

void borrowBookInteraction(struct Books *book, unsigned int numBooks)
{
    char output[] = "Do you want to borrow a book ? if so, enter [b], if not enter [q] : ";
    printf("%s\n", output);

    char userInput[1];
    int returnScanf = scanf("%1s", userInput);
    if(returnScanf > 1)
    {
        printf("More than one character in userInput\n");
    }
    else if(returnScanf == 0)
    {
        printf("No character\n");
    }

    switch(userInput[0])
    {
        case 'b':
            // borrow book
            char output[] = "Give the id of the book you want to borrow: ";
            printf("%s\n", output);
            unsigned int id;
            if(scanf("%u", &id) == 0)
            {
                printf("Line : %d\n", __LINE__);
                printf("scanf return 0 for the id");
            }

            unsigned int index = idToIndex(book, &numBooks, id);
            rentBook(book, numBooks, index);

            break;
        case 'q':
            break;
    }


}

void searchInteraction(bool* inloop, struct Books *book, unsigned int numBooks)
{
    char message[] = "Enter [a] if you search by author, [t] by title or [y] by year of publication or [q] to quit : ";
    printf("%s\n", message);

    char userInput[1];
    int returnScanf = scanf("%1s", userInput);
    if(returnScanf > 1)
    {
        printf("More than one character in userInput\n");
    }
    else if(returnScanf == 0)
    {
        printf("No character\n");
    }

    switch(userInput[0])
    {
        case 'a':
            searchAuthor(book, numBooks);
            break;
        case 't':
            searchTitle(book, numBooks);
            break;
        case 'y':
            searchYear(book, numBooks);
            break;
        case 'q':
            break;
    }
}

void returnInteraction(bool* inloop, struct Books *book, unsigned int numBooks)
{
    char output[] = "Do you want to return a book to the library ? if so, enter [r], if not enter [q] : ";
    printf("%s\n", output);

    char userInput[1];
    int returnScanf = scanf("%1s", userInput);
    if(returnScanf > 1)
    {
        printf("More than one character in userInput\n");
    }
    else if(returnScanf == 0)
    {
        printf("No character\n");
    }

    switch(userInput[0])
    {
        case 'r':
            // borrow book
            char output[] = "Give the id of the book you want to return: ";
            printf("%s\n", output);
            unsigned int id;
            if(scanf("%u", &id) == 0)
            {
                printf("Line : %d\n", __LINE__);
                printf("scanf return 0 for the id");
            }

            unsigned int index = idToIndex(book, &numBooks, id);

            returnBook(book, numBooks, index);
            break;
        case 'q':
            break;
    }
}

void interactionWithTheUser(bool* inloop, char value, Library* library)
{
    //Books* books = library->lstBook;
    unsigned int (*numBooks) = &(library->nbBook);

    switch(value)
    {
        case 'q':
            *inloop = false;
            break;
        case 'l':
            char output[] = "Do you want to see borrowed books ? [y/n] ";
            printf("%s\n", output);
            char yesOrNo[1];

            if(scanf("%1s",yesOrNo) == 0)
            {
                printf("Line :%d\n", __LINE__ );
                printf("[y] or [n] need to be entered\n");
            }

            switch(yesOrNo[0])
            {
                case 'y':
                    showBooks(library->lstBook, *numBooks, BORROWED);
                    break;
                case 'n':
                    showBooks(library->lstBook, *numBooks, AVAILABLE);
                    break;
                default:
                    showBooks(library->lstBook, *numBooks, AVAILABLE);
                    break;
            }


            //printf("%d\n", *numBooks);
            break;
        case 'a':
            library->lstBook = addBookInteraction(library->lstBook, numBooks);
            //printf("%d\n", *numBooks);
            break;
        case 'b':
            borrowBookInteraction(library->lstBook, *numBooks);

            break;
        case 's':
            searchInteraction(inloop, library->lstBook, *numBooks);

            break;
        case 'r':
            returnInteraction(inloop, library->lstBook, *numBooks);

            break;
        case 'd':
            library->lstBook = deleteBookInteraction(library->lstBook, numBooks);
            break;
    }

}
