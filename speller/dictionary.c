// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    /*
    Variable:
    HASH_LENGTH
    Character

    Input:
    String word which will be hashed

    Process:
    For loop through
    Get ASCII value of first 3 letter of word
        - First check if letter exits
            - If yes, get it ASCII value and add it to sum
            - If not, return the sum
    Return Sum

    */

    const int HASH_LENGTH = 3;
    int sum = 0;

    // Hash first three letter of word if they exist
    for(int i = 0; i < HASH_LENGTH; i++) {
        if (word[i] != '\0') {
            sum += toupper(word[i]) - 'A';
        } else {
            return sum;
        }
    }
    return sum
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    /*
    User Interface:
    User will give path to dictionary and put everything in that file to memory

    Input:
    Dictionary

    Process:
    Open the file, check if really opened (I saw how to open file in speller.c, copy that method)
        - If file not opened return false
    Read a word (Hello or Peacock) from file, hash first word and put output into value
    Put word into index of hash table based on what value
    Close the file
    Return True

    Output:
    Status of whatever Dictionary loaded into memory (true/false), if was able or not able to respectively
    */

   FILE *file = fopen(dictionary, "r");
   if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
