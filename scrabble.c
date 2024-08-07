#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(const char *word);

int main(void)
{
    // Get input from both players
    char word1[100], word2[100];
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

int compute_score(const char *word)
{
    // Points assigned to each letter of the alphabet
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;

    // Compute score for the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            // Convert letter to uppercase
            char upper = toupper(word[i]);
            // Find the score for the letter (subtract 'A' to get index)

            score += points[upper - 'A']; // lets say B is a word -> B - A -> 66 - 65 -> 1
        }
    }

    return score;
}
