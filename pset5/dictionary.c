// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
struct node
{
    char word[LENGTH + 1];
    struct node *next;
};

typedef struct node node_t;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node_t *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    bool statement = true;
    char word[100];
    unsigned int i = 0;

    node_t *head = NULL;
    node_t *temporary;

    FILE *file = fopen(dictionary, "r");
        if(file == NULL){
            printf("Couldn't find/open a file: %c", *dictionary);

            statement = false;
            return statement;
        }
            //  node *table[N];
            while(fscanf(file, "%s", word)!=EOF)
            {
            ++i;
            temporary = create_new_node(i, word);
            temporary->next = head;
            head = temporary;

            //printf("%s ", temporary->word);
            //printf("%i\n",i);
            }

    return false;//statement;
}

// Creating new node func
node_t *create_new_node(unsigned int inc, const char *word) {
    node_t *result = malloc(sizeof(node_t));
    strcpy(result->word, word);
    result->next = NULL;

    return result;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
