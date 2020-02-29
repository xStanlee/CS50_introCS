// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Hashtable size for a nodes

#define TABLE_SIZE 16384

// Node struct


typedef struct node node_t;

// Prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
node_t *create_new_node(unsigned int inc, const char* word);

#endif // DICTIONARY_H
