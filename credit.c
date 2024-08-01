#include <stdio.h>
#include <cs50.h> // For get_long function
#include <string.h>

// Function prototypes
bool luhn_algorithm(long card_number);
void check_card_type(long card_number);

int main(void)
{
    long card_number = get_long("Number: ");

    if (luhn_algorithm(card_number))
    {
        check_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

// Function to implement Luhn's Algorithm
bool luhn_algorithm(long card_number)
{
    int sum = 0;
    bool alternate = false;

    while (card_number > 0)
    {
        int digit = card_number % 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit / 10 + digit % 10;
            }
        }

        sum += digit;
        alternate = !alternate;
        card_number /= 10;
    }

    return (sum % 10 == 0);
}

// Function to check card type based on starting digits and length
void check_card_type(long card_number)
{
    int length = 0;
    long start_digits = card_number;

    while (start_digits > 0)
    {
        start_digits /= 10;
        length++;
    }

    // Reset start_digits to first two digits
    start_digits = card_number;
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    if ((start_digits == 34 || start_digits == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if ((start_digits >= 51 && start_digits <= 55) && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((start_digits / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

