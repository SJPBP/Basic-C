#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letterCounter(string word);
int sentenceCounter(string word);
int wordCounter(string word);

int main(void)
{
    string Text = get_string("Text: ");

    double letterCount = letterCounter(Text);
    double sentenceCount = sentenceCounter(Text);
    double wordCount = wordCounter(Text);

    double L = ((letterCount / wordCount) * 100);
    double S = ((sentenceCount / wordCount) * 100);
    float gradeIndex = round((0.0588 * L) - (0.296 * S) - 15.8);

    printf("%.0f letters\n", letterCount);
    printf("%.0f words\n", wordCount);
    printf("%.0f sentences\n", sentenceCount);

    // Check bounds on index
    if (gradeIndex >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (gradeIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", gradeIndex);
    }

    return 0;
}

/**
 * Counts the number of letters in the given string.
 *
 * Only counts alpha characters, ignoring any spaces, punctuation, etc.
 *
 * word: The string to analyze
 *
 * Returns: Number of alphabetic letters found
*/
int letterCounter(string word)
{
    // Initialize counter
    int letterCount = 0;

    // Iterate over each character
    for (int i = 0; i < strlen(word); i++)
    {
        // Check if character is alphabetic
        if (isalpha(word[i]) != 0)
        {
            // Increment count if alphabetic
            letterCount++;
        }
    }

    return letterCount;
}

/**
 * Counts the number of sentences in the given string.
 * Sentences are identified by ! . or ? delimiters.
 *
 * word: The string to analyze
 *
 * Returns: Number of sentences found
*/
int sentenceCounter(string word)
{
    // Initialize counter
    int sentenceCount = 0;

    // Check delimiters
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == '!' || word[i] == '.' || word[i] == '?')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

/**
 * Counts the number of words in the given string.
 * Words are identified by space, tab, or newline delimiters.
 *
 * word: The string to analyze
 *
 * Returns: Number of words found
*/
int wordCounter(string word)
{
    // Initialize counter
    int wordCount = 0;

    // Check delimiters
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == ' ' || word[i] == '\n' || word[i] == '\t')
        {
            wordCount++;
        }
    }
    return wordCount + 1; // Account for last word 
}