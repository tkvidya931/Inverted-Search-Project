#include<stdio.h>
#include<ctype.h>
#include "inverted_search.h"

hash_t arr[27];
void init_hash_table()
{
    for (int i = 0; i < 27; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
}

/*Checks a word already exists in  file*/
sub_node_t* find_sub_node(main_node_t *main, const char *filename)
{
    sub_node_t *temp = main->sublink;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, filename) == 0)
            return temp; // found
        temp = temp->link;
    }
    return NULL; // not found
}
//insert word into data base
int insert_word(char *word, char *filename)
{
    int index;
   
    index = tolower(word[0])- 'a';
     if (!isalpha(word[0]))
          index=26;
    main_node_t *mtemp = arr[index].link;
    main_node_t *mprev = NULL;

    // Search main node
    while (mtemp != NULL)
    {
        if (strcmp(mtemp->word, word) == 0)
            break;
        mprev = mtemp;
        mtemp = mtemp->link;
    }

    if (mtemp == NULL)
    {
        // Create main node
        main_node_t *new_main = malloc(sizeof(main_node_t));
        if (!new_main) 
           return FAILURE;

        strcpy(new_main->word, word);
        new_main->file_count = 1;
        new_main->link = NULL;

        // Create sub node
        sub_node_t *new_sub = malloc(sizeof(sub_node_t));
        if (!new_sub) 
            return FAILURE;

        strcpy(new_sub->file_name, filename);
        new_sub->word_count = 1;
        new_sub->link = NULL;

        new_main->sublink = new_sub;
        // Insert at beginning or after previous
        if (mprev == NULL)
            arr[index].link = new_main;
        else
            mprev->link = new_main;
    }
    else
    {
        // Main node exists → check sub node
        sub_node_t *sub = find_sub_node(mtemp, filename);
        if (sub == NULL)
        {
            // Create sub node
            sub_node_t *new_sub = malloc(sizeof(sub_node_t));
            if (!new_sub) 
                return FAILURE;

            strcpy(new_sub->file_name, filename);
            new_sub->word_count = 1;
            new_sub->link = mtemp->sublink; // insert at beginning
            mtemp->sublink = new_sub;
            mtemp->file_count++;
        }
        else
        {
            // Word exists in file → increment count
            sub->word_count++;
        }
    }

    return SUCCESS;
}
int create_database(FileNode* head)
{
    char word[50];

    while (head != NULL)
    {
        FILE *fptr = fopen(head->filename, "r");
        if (!fptr)
        {
            printf(RED"Error opening file %s\n"RESET, head->filename);
            return FAILURE;
        }

        while (fscanf(fptr, "%s", word) != EOF)
        {
            insert_word(word, head->filename);
        }

        fclose(fptr);
        head = head->link;
    }

    return SUCCESS;
}
