#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct reader{            // Define structure reader
        int id;               // id stores reader id
        char name[20];        // name stores reader's name
        char due;             // due stores y/n for if any book is due by particular reader
        int dbid;            // dbid stores due book's id
    } rdr[10] = {0};         // rdr array is initialized with structure of reader

    struct book{                // Structure book defined
        int id;                 // id here stores book id
        char name[30];          // name stores name of the book
        char author[20];        // author stores name of the author
        char avbl;              // avbl stores availability of the book as y/n
        int rid;                // rid stores reader id having the book
    } bk[20] = {0};            // bk array is initialized with structure of book

    int choice, searchid, n;   // Some integer variables are declared to be used for performing different functions in the program

    printf("\n\t\tWELCOME!\n");   // Welcome message

    do { // Do-while loop is used to return to the main menu after every case is over i.e., task is done
        printf("\n\tLibrary Management System\n\t=========================\n1. Add new book\t\t2. Search book\n3. Add new reader\t4. Search reader\n5. Issue book\t\t6. Submit book\n7. Delete book\t\t8. Delete reader\n9. List of books\t10. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add a book
                for (int i = 0; i < 20; i++) {
                    if (bk[i].id == 0) { // To find empty space in bk array
                        printf("Enter name of the book: ");
                        scanf("%s", bk[i].name);
                        printf("Enter name of the author: ");
                        scanf("%s", bk[i].author);
                        printf("Enter book ID: ");
                        scanf("%d", &bk[i].id);
                        bk[i].avbl = 'y'; // Set availability to y
                        bk[i].rid = 0;    // Set reader's id to 0 as default
                        printf("Book added successfully.\n\n");
                        break; // Exit from for loop
                    }
                }
                break;

            case 2: // Search book
                printf("Enter book ID: ");
                scanf("%d", &searchid);
                n = 0;
                for (int i = 0; i < 20; i++) {
                    if (searchid == bk[i].id) {
                        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %c\tDue by Reader ID: %d\n",
                            bk[i].id, bk[i].name, bk[i].author, bk[i].avbl, bk[i].rid);
                        n++;
                    }
                }
                if (n == 0) {
                    printf("Book not found.\n\n");
                }
                break;

            case 3: // Add a new reader
                for (int i = 0; i < 10; i++) {
                    if (rdr[i].id == 0) { // To find empty space in rdr array
                        printf("Enter Reader's name: ");
                        scanf("%s", rdr[i].name);
                        printf("Enter Reader id: ");
                        scanf("%d", &rdr[i].id);
                        rdr[i].due = 'n';
                        rdr[i].dbid = 0;
                        printf("Reader added successfully.\n\n");
                        break; // Exit from for loop
                    }
                }
                break;

            case 4: // Search reader
                printf("Enter Reader ID: ");
                scanf("%d", &searchid);
                n = 0;
                for (int i = 0; i < 10; i++) {
                    if (searchid == rdr[i].id) {
                        printf("\n\tReader Information\nReader ID: %d\tReader Name: %s\nDue: %c\t\tDue book ID: %d\n",
                            rdr[i].id, rdr[i].name, rdr[i].due, rdr[i].dbid);
                        n++;
                    }
                }
                if (n == 0) {
                    printf("Reader not found.\n\n");
                }
                break;

            case 5:
                // Issue book logic here
                printf("Issue book functionality not implemented yet.\n\n");
                break;

            case 6:
                // Submit book logic here
                printf("Submit book functionality not implemented yet.\n\n");
                break;

            case 7:
                // Delete book logic here
                printf("Delete book functionality not implemented yet.\n\n");
                break;

            case 8:
                // Delete reader logic here
                printf("Delete reader functionality not implemented yet.\n\n");
                break;

            case 9:
                // List of books logic here
                printf("List of books functionality not implemented yet.\n\n");
                break;

            case 10:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 10.\n\n");
                break;
        }
    } while (choice != 10); // Continue until user chooses to exit

    return 0;
}