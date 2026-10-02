
#include <stdio.h>
#include <string.h>
#include "book.h"
#include "issue.h"

Issue issues[MAX_ISSUES];
int issueCount = 0;

void issueBook()
{
    int i;
    int bookId;

    printf("\n========== ISSUE BOOK ==========\n");

    printf("Enter Issue ID : ");
    scanf("%d", &issues[issueCount].issueId);

    printf("Enter Book ID : ");
    scanf("%d", &bookId);

    for(i = 0; i < bookCount; i++)
    {
        if(books[i].bookId == bookId)
        {
            if(books[i].quantity == 0)
            {
                printf("\nBook Not Available!\n");
                return;
            }

            issues[issueCount].bookId = bookId;

            printf("Enter User ID : ");
            scanf("%d", &issues[issueCount].userId);

            printf("Enter User Name : ");
            scanf(" %[^\n]", issues[issueCount].userName);

            printf("Enter Issue Date (dd/mm/yyyy): ");
            scanf("%s", issues[issueCount].issueDate);

            printf("Enter Due Date (dd/mm/yyyy): ");
            scanf("%s", issues[issueCount].dueDate);

            strcpy(issues[issueCount].returnDate, "Not Returned");

            issues[issueCount].fine = 0;
            issues[issueCount].status = 0;

            books[i].quantity--;

            issueCount++;

            printf("\nBook Issued Successfully...\n");
            return;
        }
    }

    printf("\nBook ID Not Found!\n");
}

void returnBook()
{
    int issueId, i, j;

    printf("\n========== RETURN BOOK ==========\n");

    printf("Enter Issue ID : ");
    scanf("%d", &issueId);

    for(i = 0; i < issueCount; i++)
    {
        if(issues[i].issueId == issueId)
        {
            if(issues[i].status == 1)
            {
                printf("\nBook Already Returned!\n");
                return;
            }

            printf("Enter Return Date (dd/mm/yyyy): ");
            scanf("%s", issues[i].returnDate);

            printf("Enter Fine Amount : ");
            scanf("%d", &issues[i].fine);

            issues[i].status = 1;

            for(j = 0; j < bookCount; j++)
            {
                if(books[j].bookId == issues[i].bookId)
                {
                    books[j].quantity++;
                    break;
                }
            }

            printf("\nBook Returned Successfully...\n");
            return;
        }
    }

    printf("\nIssue Record Not Found!\n");
}


void listIssuedBooks()
{
    int i;

    if(issueCount == 0)
    {
        printf("\nNo Issued Books Available!\n");
        return;
    }

    printf("\n================ ISSUED BOOKS ================\n");

    printf("%-8s %-8s %-8s %-20s %-12s %-12s %-15s %-6s\n",
           "IssueID","BookID","UserID","User Name",
           "IssueDate","DueDate","ReturnDate","Fine");

    printf("--------------------------------------------------------------------------\n");

    for(i = 0; i < issueCount; i++)
    {
        printf("%-8d %-8d %-8d %-20s %-12s %-12s %-15s %-6d\n",
               issues[i].issueId,
               issues[i].bookId,
               issues[i].userId,
               issues[i].userName,
               issues[i].issueDate,
               issues[i].dueDate,
               issues[i].returnDate,
               issues[i].fine);
    }
}

void saveIssuedBooks()
{
    FILE *fp;

    fp = fopen("issued.dat", "wb");

    if(fp == NULL)
    {
        printf("\nCannot Open File!\n");
        return;
    }

    fwrite(&issueCount, sizeof(int), 1, fp);
    fwrite(issues, sizeof(Issue), issueCount, fp);

    fclose(fp);

    printf("\nIssued Books Saved Successfully...\n");
}

void loadIssuedBooks()
{
    FILE *fp;

    fp = fopen("issued.dat", "rb");

    if(fp == NULL)
        return;

    fread(&issueCount, sizeof(int), 1, fp);
    fread(issues, sizeof(Issue), issueCount, fp);

    fclose(fp);
}
