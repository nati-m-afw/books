#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bk_type
{
    char title[100];
    int pages;
    char author[50];
    struct bk_type *next;
};

typedef struct bk_type Book;

Book *start=NULL;

void addBook(){
    Book *book1 = (Book*) malloc(sizeof(Book));

    printf("\nEnter title: ");
    scanf("%s", &book1->title);
    printf("Enter number of pages: ");
    scanf("%d", &book1->pages);
    printf("Enter author: ");
    scanf("%s", &book1->author);

    // Set next to the front node for new node
    book1->next = start;

    // Make new node the front node
    start = book1;
}


void displayBooks(){
    Book *tmp = start;

    if (!start){
        printf("\nThere are no books in the library. \n");
    }
    else{
        while (tmp != NULL)
        {
            printf("\nBook Title: %s \n", tmp->title);
            printf("Author: %s \n", tmp->author);
            printf("Pages: %d \n", tmp->pages);
            tmp = tmp->next;
        }
        
    }
}

void checkoutBook(char *title){
    Book *tmp = start;

    if (!start){
        printf("\nThere are no books in the library. \n");
        return;
    }
    
    while (tmp && strcmp(tmp->title, title))
    {
        tmp = tmp->next;
    }

    if (tmp && !strcmp(tmp->title, title))
    {
        printf("\n----Book Found---\n");
        printf("Book Title: %s \n", tmp->title);
        printf("Author: %s \n", tmp->author);
        printf("Pages: %d \n", tmp->pages);
        return;
    }
    
    printf("\nBook not found!\n");
}

void deleteBook(char *title){
    Book *tmp = start;
    Book *prev;

    if (!start){
        printf("\nThere are no books in the library. \n");
        return;
    }
    else if(!strcmp(start->title, title)){
        start = start->next;
        free(tmp);
        printf("\nDeleted book!\n");
        return;
    }
    
    while (tmp && strcmp(tmp->title, title))
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (!tmp){
        printf("\nBook not found!\n");
        return;
    }

    if (tmp->next != NULL)
        prev->next = tmp->next;
    else
        prev->next = NULL;

    free(tmp);
    printf("\nDeleted book!\n");
}

int main(){
    // addBook();
    // displayBooks();
    // deleteBook("ds");
    // checkoutBook("ds");
    int choice;
    char param[100];

    while (1)
    {
        printf("\n1 - to add new book\n");
        printf("2 - to display books in the library\n");
        printf("3 - to search for book\n");
        printf("4 - to delete book\n");
        printf("5 - to quit\n>");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            printf("Enter title: ");
            scanf("%s", &param);
            checkoutBook(param);
            break;
        case 4:
            printf("Enter title: ");
            scanf("%s", &param);
            deleteBook(param);
            break;
        case 5:
            _exit(0);
            break;
        default:
            printf("Invalid input! Enter a valid input\n");
            break;
        }
    }
    
    
    return 0;
}