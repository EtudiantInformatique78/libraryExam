#include <stdio.h>

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

    if(state == 1)
    {
        printf("The book is not available for now.\n");
        printf("Remaining days : %d\n", book->remainingDays);
    }
    else
    {
        printf("The book is available to borrow.")
        printf("You can borrow it now :\n");
    }
}

int main(int argc, char** argv)
{

    return 0;
}
