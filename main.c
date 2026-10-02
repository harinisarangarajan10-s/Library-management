#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "issue.h"

int main()
{
    int choice;

    loadBooks();
    loadIssuedBooks();

    while(1)
    {
        printf("\n====================================");
        printf("\n LIBRARY MANAGEMENT SYSTEM");
        printf("\n====================================");

        printf("\n1. Add New Book");
        printf("\n2. Update Book Details");
        printf("\n3. Remove Book");
        printf("\n4. Search Book");
        printf("\n5. View All Books");
        printf("\n6. Issue Book");
        printf("\n7. Return Book");
        printf("\n8. List Issued Books");
        printf("\n9. Save Data");
        printf("\n10. Exit");

        printf("\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                updateBook();
                break;

            case 3:
                removeBook();
                break;

            case 4:
                searchBook();
                break;

            case 5:
                viewBooks();
                break;

            case 6:
                issueBook();
                break;

            case 7:
                returnBook();
                break;

            case 8:
                listIssuedBooks();
                break;

            case 9:
                saveBooks();
                saveIssuedBooks();
                printf("\nData Saved Successfully...\n");
                break;

            case 10:
                saveBooks();
                saveIssuedBooks();
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
