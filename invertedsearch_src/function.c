#include<stdio.h>
#include"inverted_search.h"
#include<ctype.h>

// Returns 1 if the file already exists in the list, 0 otherwise

int check_duplicate(FileNode *head, char *fname)
{
    while (head != NULL)               // traverse the list
    {
        if (strcmp(head->filename, fname) == 0)
            return 1;                  // duplicate found
        head = head->link;             // move to next node
    }
    return 0;                          // no duplicate
}

void insert_at_end(FileNode **head, char *fname)
{
    FileNode *new_node = malloc(sizeof(FileNode)); // create a new node
    if (new_node == NULL) return;                  // check malloc
    strcpy(new_node->filename, fname);            // copy file name
    new_node->link = NULL;                         // last node points to NULL

    if (*head == NULL)                             // empty list?
    {
        *head = new_node;                          // new node becomes head
        return;
    }

    // traverse to the end
    FileNode *temp = *head;
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = new_node;                         // attach new node at the end
}
