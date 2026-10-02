/* issue.h */

#ifndef ISSUE_H
#define ISSUE_H

#define MAX_ISSUES 100

typedef struct
{
    int issueId;
    int bookId;
    int userId;
    char userName[100];
    char issueDate[20];
    char dueDate[20];
    char returnDate[20];
    int fine;
    int status;      // 0 = Issued, 1 = Returned
} Issue;

extern Issue issues[MAX_ISSUES];
extern int issueCount;

/* Issue Management Functions */
void issueBook();
void returnBook();
void listIssuedBooks();

/* File Handling */
void saveIssuedBooks();
void loadIssuedBooks();

#endif
