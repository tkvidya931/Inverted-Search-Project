#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H
#define SUCCESS 0
#define FAILURE 1
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RED   "\033[31m"
#define ROSE "\033[1;35m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_node
{
    char filename[100];
    struct file_node *link;
} FileNode;
//for to store one word in a data base we need to create one main node and sub node
typedef struct node1
{
    int word_count;
    char file_name[25];
    struct node1* link;
}sub_node_t;
typedef struct node
{
    int file_count;
    char word[50];
    sub_node_t* sublink;//points to file list
    struct node* link;
}main_node_t;


//for hash table
typedef struct hash_node
{
int index;
main_node_t* link;//points to word list
}hash_t;
extern hash_t arr[27];
// Function declarations
int check_duplicate(FileNode *head, char *fname);
int insert_word(char *word, char *filename);
void insert_at_end(FileNode **head, char *fname);
void print_list(FileNode *head);
void init_hash_table();
int  create_database(FileNode *head);
void search_database(FileNode* head);
void display_database();
void update_database();
void save_database();

#endif
