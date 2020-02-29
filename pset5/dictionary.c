#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

struct node
{
    char word[LENGTH + 1];
    struct node *next;
};

typedef struct node *node_t;

// Hash table of
node_t hashtable[TABLE_SIZE];

// track of number of words
unsigned long words = 0;

// Prototype of a node
node_t make_node(const char *key);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Lowercase of words
    char copy[strlen(word) + 1];
    strcpy(copy, word);
    char *p = copy;
    for ( ; *p; ++p) *p = tolower(*p);

    unsigned long hash = djb2(copy) % TABLE_SIZE;
    node_t cursor = hashtable[hash];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, copy) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    // Hashtable as started
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    char buffer[LENGTH];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        // Dict should contain only lowercase words
        node_t node = make_node(buffer);

        unsigned long hash = djb2(buffer) % TABLE_SIZE;
        if (hashtable[hash] != NULL)
        {
            node->next = hashtable[hash];
        }

        hashtable[hash] = node;

        words++;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        node_t cursor = hashtable[i];

        while (cursor != NULL)
        {
            node_t temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}

// Makes a singly one way linked list node
node_t make_node(const char *key)
{
    node_t node = malloc(sizeof(struct node));
    strcpy(node->word, key);
    node->next = NULL;
    return node;
}

// Algorithm from stolen http://www.cse.yorku.ca/~oz/hash.html

unsigned long djb2(const void *_str)
{
  const char *str = _str;
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
  {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c (33 is the fastest compose)*/
  }

  return hash;
}
