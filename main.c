#include <stdio.h>
#include <stdbool.h>


void printArgumentShow()
{
    char show[] = "Hey ! Use [q] to quit, [l] to list books, [a] to add a book, [s] to search a book, [e] to edit a book or [d] to delete a book";
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

void interactionWithTheUser(bool* inloop, char value)
{
    switch(value)
    {
        case 'q':
            *inloop = false;
            break;
        case 'l':
            //showBooks();

            break;
        case 'a':

            break;
        case 's':

            break;
        case 'e':

            break;
        case 'd':

            break;
    }
}

typedef struct Books
{
    char title[20];
    char autor[20];
    int publicationYear;
    bool state;
    int remainingDays;

}Books;

void showBooks(const struct Books *book)
{
    printf("Title : %s\n", book->title);
    printf("Autor : %s\n", book->autor);
    printf("Publication Year : %d\n", book->publicationYear);
    bool state = true;
    if(state)
    {
        printf("The book is not available for now.\n");
        printf("Remaining days : %d\n", book->remainingDays);
    }
    else
    {
        printf("The book is available to borrow.");
        printf("You can borrow it now :\n");
    }
}


int main(int argc, char** argv)
{

    char userChoice[1];
    bool inloop = true;


    while(inloop)
    {
        getUserInput(userChoice);
        interactionWithTheUser(&inloop, userChoice[0]);

    }

    return 0;
}
