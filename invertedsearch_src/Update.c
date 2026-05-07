#include"inverted_search.h"
#include<ctype.h>
#include<stdlib.h>

void update_database(FileNode* head)
{
    char filename[50];
    char line[200];

    printf("Enter the file name: ");
    scanf("%s", filename);

    if (strstr(filename, ".txt") == NULL)
    {
        printf("Error: Please enter a valid .txt file name!\n");
        return ;
    }

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error: Unable to open file\n");
        return;
    }

    while (fscanf(fptr, "%s", line) != EOF)
    {
        int len = strlen(line);

        if (line[0] != '#' || line[len - 1] != '#')
            continue;

        char *token = strtok(&line[1], ";");

        int index = atoi(token);

        main_node_t *mnew = malloc(sizeof(main_node_t));

        token = strtok(NULL, ";");
        mnew->file_count = atoi(token);

        token = strtok(NULL, ";");
        strcpy(mnew->word, token);

        mnew->sublink = NULL;

        int file_count = mnew->file_count;

        sub_node_t *prev = NULL;

        for (int i = 0; i < file_count; i++)
        {
            sub_node_t *snew = malloc(sizeof(sub_node_t));

            token = strtok(NULL, ";");
            snew->word_count = atoi(token);

            token = strtok(NULL, ";");
            strcpy(snew->file_name, token);

            snew->link = NULL;

            if (prev == NULL)
                mnew->sublink = snew;
            else
                prev->link = snew;

            prev = snew;
        }

        mnew->link = arr[index].link;
        arr[index].link = mnew;
    }

    fclose(fptr);
}