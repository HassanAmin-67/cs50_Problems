#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
char encrypt_char(char ch, string key);

int main(int argc, string argv[])
{
    // Check if exactly one command-line argument is provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", encrypt_char(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    // Check if key is 26 characters long
    if (strlen(key) != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    // Check if key contains only alphabetic characters and each character is unique
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Map the letter to its position in the alphabet
        int index = tolower(key[i]) - 'a';

        // Check if the letter has been seen before
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }
    return true;
}

char encrypt_char(char ch, string key)
{
    // If character is alphabetic, perform the substitution
    if (isalpha(ch))
    {
        if (isupper(ch))
        {
            return toupper(key[ch - 'A']);
        }
        else
        {
            return tolower(key[ch - 'a']);
        }
    }

    // If character is not alphabetic, return it unchanged
    return ch;
}
