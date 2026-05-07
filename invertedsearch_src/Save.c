#include<stdio.h>
#include"inverted_search.h"


void save_database()
{
    char filename[50];

    while (1)
    {
        printf("Enter the file name to save database: ");
        scanf("%s", filename);

        if (strstr(filename, ".txt") == NULL)
        {
            printf(RED "Error: Please enter a valid .txt file name!\n" RESET);
        }
        else
        {
            break;   // valid name
        }
    }

    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf(RED "Unable to create file\n" RESET);
        return;
    }

    //fprintf(fptr, "#index;filecount;word;wordcount;filename;#\n");
    
    for (int i = 0; i < 27; i++)
{
    main_node_t *mtemp = arr[i].link;

    while (mtemp != NULL)
    {
        fprintf(fptr, "#%d;%d;%s;",i, mtemp->file_count, mtemp->word);

        sub_node_t *stemp = mtemp->sublink;

        while (stemp != NULL)
        {
            fprintf(fptr, "%d;%s;", stemp->word_count,stemp->file_name);
             stemp = stemp->link;
        }

        fprintf(fptr, "#\n");

        mtemp = mtemp->link;
    }
}
    

    fclose(fptr);  

    printf("Database saved successfully to %s\n", filename);
}


