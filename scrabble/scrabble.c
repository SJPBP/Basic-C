#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // Length of word
    int Length = strlen(word);

    // Total total score for word
    int Score = 0;

    // Loop through all the letter of word
    for (int i = 0; i < Length; i++)
    {
        // Check letter is in alphabetical
        if (isalpha(word[i]) != 0)
        {
            // Check if letter from word is in Upper case
            if (isupper(word[i]) != 0)
            {
                int upper_num = POINTS[word[i] - 65];
                Score += upper_num;
            }
            // letter from word is lower case
            else
            {
                int lower_num = POINTS[word[i] - 97];
                Score += lower_num;
            }
        }
        // If not add zero to score
        else
        {
            Score += 0;
        }
    }

    // Return Total score of word
    return Score;
}
