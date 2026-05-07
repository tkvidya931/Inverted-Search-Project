/*              Name :VIDYA T K
  Name of the project:Inverted search 
          Description:The Inverted Search Project is a data structures–based application developed in C that
                     implements an efficient word-searching mechanism using the concept of inverted indexing. 
                     The primary objective of this project is to create a searchable database from multiple text
                     files and enable fast retrieval of information.
                     In this system, data is organized in an inverted format where each word is mapped to the
                     list of   files in which it appears along with its frequency of occurrence. A hash table combined
                     with linked  lists is used to efficiently store and manage the indexed data. The hashing technique 
                     helps in quick  access to words based on their initial character, thereby reducing search time and 
                     improving performance.
                     The application allows users to create a database from input files, display the indexed content, 
                     search for  specific words, and optionally save or update the database. This project demonstrates 
                     practical implementation of  core data structure concepts such as hashing, dynamic memory allocation, 
                     linked lists, file handling, and  string manipulation.
                Date:28/02/2026*/

#include <stdio.h>
#include <string.h>
#include "inverted_search.h"

int main(int argc, char *argv[])
{
    int option;   //Declare option

    if (argc < 2)
    {
        printf("Usage: ./a.out file1.txt file2.txt ...\n");
        return 0;
    }

    FileNode *head = NULL;

    for (int i = 1; i < argc; i++)
    {
        // Check .txt extension
        if (strstr(argv[i], ".txt") == NULL)
        {
            printf(RED"Error: %s is not a .txt file\n"RESET, argv[i]);
            continue;
        }

        FILE *fptr = fopen(argv[i], "r");
        if (fptr == NULL)
        {
            printf(RED"Error: Unable to open %s\n"RESET, argv[i]);
            continue;
        }

        // Check if empty
        fseek(fptr, 0, SEEK_END);
        if (ftell(fptr) == 0)
        {
            printf(RED"Error: %s is empty\n"RESET, argv[i]);
            fclose(fptr);
            continue;
        }
        rewind(fptr);

        // Check duplicate
        if (check_duplicate(head, argv[i]))
        {
            printf(RED"Error: %s already added\n"RESET, argv[i]);
            fclose(fptr);
            continue;
        }

        insert_at_end(&head, argv[i]);
        printf("%s successfully added\n", argv[i]);

        fclose(fptr);
    }

 if (head != NULL)
  { 
    int is_created=0;
   while (1)
     {
     printf(BLUE "\nMenu\n" RESET);
     printf(YELLOW "1. Create Database\n2. Search Database\n3. Update Database\n4. Display Database\n5. Save Database\n6. Exit\n\n"RESET);
     printf("Enter the option: ");
     scanf("%d", &option);
    
    switch (option)
      {
      case 1:
            if(is_created)
               printf("Error!Data base is already created");
           else
            {
             printf("\nCreating database...\n");
            if(create_database(head)==SUCCESS)
             {
              is_created=1;
              printf("Database created successfully!\n");
             }
             else
             {
              printf("data base creation failed!");
             }
           }
           break;
     case 2:
            search_database(head);
            break;
     case 3:
              update_database();
              is_created=1;
            break;
     case 4:
             display_database();
             break;
     case 5:
            save_database();
            break;
     case 6:
            printf("Exiting...\n");
            return 0;   // exit
      
    default:
            printf(RED"Invalid option\n"RESET);
       }
      }
    }

    return 0;
}
