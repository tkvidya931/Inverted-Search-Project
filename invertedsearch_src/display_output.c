
#include "inverted_search.h"
#include <stdio.h>
void print_list(FileNode *head)
  {
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nValidated File List:\n");
    printf("---------------------\n"RESET);

    while (head != NULL)
    {
        printf("%s -> ", head->filename);
        head = head->link;
    }

    printf("NULL\n");
}


void display_database()
{
    printf("\n");

    printf(ROSE "+-------+------------+-----------------+------------+----------------------+\n" RESET);
    printf(ROSE "|" RESET WHITE " %-5s " RESET
           ROSE "|" RESET WHITE " %-10s " RESET
           ROSE "|" RESET WHITE " %-15s " RESET
           ROSE "|" RESET WHITE " %-10s " RESET
           ROSE "|" RESET WHITE " %-20s " RESET
           ROSE "|\n" RESET,
           "Index", "FileCount", "Word", "WordCount", "FileName");

    printf(ROSE "+-------+------------+-----------------+------------+----------------------+\n" RESET);

    for (int i = 0; i < 27; i++)
    {
        main_node_t *mtemp = arr[i].link;

        while (mtemp != NULL)
        {
            sub_node_t *stemp = mtemp->sublink;
            int first_row = 1;

            while (stemp != NULL)
            {
                printf(ROSE "|" RESET);

                if (first_row)
                {
                    printf(WHITE " %-5d " RESET, i);
                    printf(ROSE "|" RESET);
                    printf(WHITE " %-10d " RESET, mtemp->file_count);
                    printf(ROSE "|" RESET);
                    printf(WHITE " %-15s " RESET, mtemp->word);
                    first_row = 0;
                }
                else
                {
                    printf(WHITE " %-5s " RESET, "");
                    printf(ROSE "|" RESET);
                    printf(WHITE " %-10s " RESET, "");
                    printf(ROSE "|" RESET);
                    printf(WHITE " %-15s " RESET, "");
                }

                printf(ROSE "|" RESET);
                printf(WHITE " %-10d " RESET, stemp->word_count);
                printf(ROSE "|" RESET);
                printf(WHITE " %-20s " RESET, stemp->file_name);
                printf(ROSE "|\n" RESET);

                stemp = stemp->link;
            }

            printf(ROSE "+-------+------------+-----------------+------------+----------------------+\n" RESET);

            mtemp = mtemp->link;
        }
    }
}