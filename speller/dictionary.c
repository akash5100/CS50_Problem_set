// Implements a dictionary's functionality
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>

#define SIZE 5381

// Represents a node in a hash table
typedef struct node 
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//set number of words loaded
int word_count =0;

// Hash table
node *table[SIZE];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n=strlen(word);
    char copy[n+1] ;
    copy[n]='\0';

    for (int i = 0; i < n; i++)
    {
        copy[i]=tolower(word[i]);
    }
    

    int index = hash(copy) % SIZE;

    node *head=table[index];

    if (head!= NULL)
    {
        node *cursor=head;
        while (cursor!=NULL)
        {
            if (strcmp(copy,cursor->word) == 0)
            {
                return true;
            }
            cursor=cursor->next;       
        }
        
    }

    return false;   
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary,"r");
    
    if(file == NULL)
    {
        fprintf(stderr, "Could not open ");
        return false;
    }
        char buffer[LENGTH+1];
        int n=LENGTH+2;
                                                    
        while(fgets(buffer,n,file) != NULL)
        {
            buffer[strlen(buffer) - 1] = '\0';
            int key = hash(buffer)%SIZE;
            
            node* head = malloc(sizeof(node));
            if (head==NULL)
            {
                fclose(file);
                return false;
            }
            strcpy(head->word,buffer);
            head->next=table[key];
            table[key] = head;
            word_count++;
        }
    fclose(file);
    return true;   
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false 
bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        node *cursor=table[i];
        node *temp=NULL;
        while(cursor!=NULL)
        {
            temp = cursor;
            cursor  = cursor->next;
            free(temp);
        }
    }
    return true;  
}

// Hashes word to a number
unsigned long hash(const char *word)
{
    unsigned long som = 5381;
    int c;

    while ((c = *word++))
        som = ((som << 5) + som) + c; 

    return som;

}

