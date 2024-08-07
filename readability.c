#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count_letters(string text)
{
    int letters = 0;
    // Loop through each character in the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character is an alphabetic letter
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    // Loop through each character in the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character is a space, indicating the end of a word
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1; // Add 1 to account for the last word
}

int count_sentences(string text)
{
    int sentences = 0;
    // Loop through each character in the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character is a sentence-ending punctuation mark
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
