

#include <stdio.h>
#include <string.h>
#include "book.h"

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook()
{
    printf("\n========== Add New Book ==========\n");

    printf("Enter Book ID : ");
    scanf("%d", &books[bookCount].bookId);

    printf("Enter Book Title : ");
    scanf(" %[^\n]", books[bookCount].title);

    printf("Enter Author Name : ");
    scanf(" %[^\n]", books[bookCount].author);

    printf("Enter Quantity : ");
    scanf("%d", &books[bookCount].quantity);

    bookCount++;

    printf("\nBook Added Successfully...\n");
}

void saveBooks()
{
    FILE *fp;

    fp = fopen("books.dat", "wb");

    if(fp == NULL)
    {
        printf("Cannot Open File!\n");
        return;
    }

    fwrite(&bookCount, sizeof(int), 1, fp);
    fwrite(books, sizeof(Book), bookCount, fp);

    fclose(fp);

    printf("\nBooks Saved Successfully...\n");
}


void loadBooks()
{
    FILE *fp;

    fp = fopen("books.dat", "rb");

    if(fp == NULL)
        return;

    fread(&bookCount, sizeof(int), 1, fp);
    fread(books, sizeof(Book), bookCount, fp);

    fclose(fp);
}


void updateBook()
{
    int choice, id, i;
    char name[100];

    printf("\n====== Update Book Details ======\n");
    printf("1. Update By Book ID\n");
    printf("2. Update By Book Name\n");
    printf("3. Back\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:

            printf("Enter Book ID : ");
            scanf("%d", &id);

            for(i = 0; i < bookCount; i++)
            {
                if(books[i].bookId == id)
                {
                    printf("\nBook Found\n");

                    printf("Enter New Title : ");
                    scanf(" %[^\n]", books[i].title);

                    printf("Enter New Author : ");
                    scanf(" %[^\n]", books[i].author);

                    printf("Enter New Quantity : ");
                    scanf("%d", &books[i].quantity);

                    printf("\nBook Updated Successfully...\n");
                    return;
                }
            }

            printf("\nBook Not Found!\n");
            break;

        case 2:

            printf("Enter Book Name : ");
            scanf(" %[^\n]", name);

            for(i = 0; i < bookCount; i++)
            {
                if(strcmp(books[i].title, name) == 0)
                {
                    printf("\nBook Found\n");

                    printf("Enter New Book ID : ");
                    scanf("%d", &books[i].bookId);

                    printf("Enter New Author : ");
                    scanf(" %[^\n]", books[i].author);

                    printf("Enter New Quantity : ");
                    scanf("%d", &books[i].quantity);

                    printf("\nBook Updated Successfully...\n");
                    return;
                }
            }

            printf("\nBook Not Found!\n");
            break;

        case 3:
            return;

        default:
            printf("\nInvalid Choice!\n");
    }
}


void removeBook()
{
    int choice, id, i, j;
    char name[100];

    printf("\n====== Remove Book ======\n");
    printf("1. Remove By Book ID\n");
    printf("2. Remove By Book Name\n");
    printf("3. Back\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:

            printf("Enter Book ID : ");
            scanf("%d", &id);

            for(i = 0; i < bookCount; i++)
            {
                if(books[i].bookId == id)
                {
                    for(j = i; j < bookCount - 1; j++)
                    {
                        books[j] = books[j + 1];
                    }

                    bookCount--;

                    printf("\nBook Removed Successfully...\n");
                    return;
                }
            }

            printf("\nBook Not Found!\n");
            break;

        case 2:

            printf("Enter Book Name : ");
            scanf(" %[^\n]", name);

            for(i = 0; i < bookCount; i++)
            {
                if(strcmp(books[i].title, name) == 0)
                {
                    for(j = i; j < bookCount - 1; j++)
                    {
                        books[j] = books[j + 1];
                    }

                    bookCount--;

                    printf("\nBook Removed Successfully...\n");
                    return;
                }
            }

            printf("\nBook Not Found!\n");
            break;

        case 3:
            return;

        default:
            printf("\nInvalid Choice!\n");
    }
}


void searchBook()
{
    int choice, id, i;
    char name[100];
    char author[100];

    printf("\n====== Search Book ======\n");
    printf("1. Search By Book ID\n");
    printf("2. Search By Book Name\n");
    printf("3. Search By Author Name\n");
    printf("4. Back\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:

            printf("Enter Book ID : ");
            scanf("%d", &id);

            for(i = 0; i < bookCount; i++)
            {
                if(books[i].bookId == id)
                {
                    printf("\nBook Found\n");
                    printf("Book ID   : %d\n", books[i].bookId);
                    printf("Title     : %s\n", books[i].title);
                    printf("Author    : %s\n", books[i].author);
                    printf("Quantity  : %d\n", books[i].quantity);
                    return;
                }
            }

            printf("\nBook Not Found!\n");
            break;

        case 2:

            printf("Enter Book Name : ");
            scanf(" %[^\n]", name);

            for(i = 0; i < bookCount; i++)
            {
                if(strcmp(books[i].title, name) == 0)
                {
                    printf("\nBook Found\n");
                    printf("Book ID   : %d\n", books[i].bookId);
                    printf("Title     : %s\n", books[i].title);
                    printf("Author    : %s\n", books[i].author);
                    printf("Quantity  : %d\n", books[i].quantity);
                    return;
                }
            }

            printf("\nBook Not Found!\n");
            break;

        case 3:

            printf("Enter Author Name : ");
            scanf(" %[^\n]", author);

            for(i = 0; i < bookCount; i++)
            {
                if(strcmp(books[i].author, author) == 0)
                {
                    printf("\nBook Found\n");
                    printf("Book ID   : %d\n", books[i].bookId);
                    printf("Title     : %s\n", books[i].title);
                    printf("Author    : %s\n", books[i].author);
                    printf("Quantity  : %d\n", books[i].quantity);
                }
            }
            break;

        case 4:
            return;

        default:
            printf("\nInvalid Choice!\n");
    }
}


void viewBooks()
{
    int i;

    if(bookCount == 0)
    {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\n=============================================\n");
    printf("             LIST OF BOOKS");
    printf("\n=============================================\n");

    printf("\n%-10s %-25s %-20s %-10s\n",
           "Book ID", "Title", "Author", "Quantity");

    printf("---------------------------------------------------------------\n");

    for(i = 0; i < bookCount; i++)
    {
        printf("%-10d %-25s %-20s %-10d\n",
               books[i].bookId,
               books[i].title,
               books[i].author,
               books[i].quantity);
    }

    printf("---------------------------------------------------------------\n");
}
