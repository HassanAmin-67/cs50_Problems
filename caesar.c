#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for only_digits
bool only_digits(string s);

// Function prototype for rotate
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Ensure the program is run with exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key consists of only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key from a string to an int
    int key = atoi(argv[1]);

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Print the ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Function to check if a string contains only digits
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by a given key
char rotate(char c, int key)
{
    // If it's an uppercase letter
    if (isupper(c))
    {
        return (c - 'A' + key) % 26 + 'A';
    }
    // If it's a lowercase letter
    else if (islower(c))
    {
        return (c - 'a' + key) % 26 + 'a';
    }
    // If it's not a letter, return the character unchanged
    else
    {
        return c;
    }
}
