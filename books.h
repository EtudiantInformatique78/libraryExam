#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

typedef enum StateBook
{
    BORROWED,
    AVAILABLE
} StateBook ;

typedef struct Books
{
    int id;
    char title[40];
    char author[40];
    int publicationYear;
    StateBook state;
    int remainingDays;

}Books;

typedef struct Library
{
    unsigned int nbBook;
    Books* lstBook;
} Library;

void showBook(struct Books *book, StateBook value);
void showBooks(struct Books *book, unsigned int numberOfBook, StateBook);


void initializeLibrary(Library* Library);
void freeLibrary(Library* library);



Books* addBooks(Books* books, unsigned int *totalBooks);
void rentBook(struct Books *books, unsigned int totalBooks, unsigned int indexALouer);
void returnBook(struct Books *books, unsigned int totalBooks, unsigned int indexALouer);
void printHeaderOfBookDatabase();

#endif // BOOKS_H_INCLUDED
