#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100

typedef struct
{
    int bookId;
    char title[100];
    char author[100];
    int quantity;
} Book;

extern Book books[MAX_BOOKS];
extern int bookCount;


void addBook();
void updateBook();
void removeBook();
void searchBook();
void viewBooks();


void saveBooks();
void loadBooks();

#endif
