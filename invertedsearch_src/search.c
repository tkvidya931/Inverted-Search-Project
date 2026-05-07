
#include "inverted_search.h"
#include<ctype.h>
#include<string.h>

void search_database(FileNode* head)
{
char word[50];
printf("Enter the word to search\n");
scanf("%s",word);
int index=tolower(word[0]-'a');
main_node_t *mtemp = arr[index].link; 
main_node_t *mprev = NULL;
int found=0;
while (mtemp != NULL)
    {
     if (strcmp(mtemp->word, word) == 0)
     {
      printf("word %s present in %d files.",word,mtemp->file_count);
      found=1;
     }        
            mtemp=mtemp->link;
       }
       if(!found)
          printf("Word not found");
}

