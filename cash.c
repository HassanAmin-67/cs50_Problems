#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int cents;

    // Prompt user for a positive integer
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int coins = 0;

    // Calculate the number of quarters
    int quarters = cents / 25;
    coins = coins + quarters;
    cents = cents - (quarters * 25);

    // Calculate the number of dimes
    int dimes = cents / 10;
    coins = coins + dimes;
    cents = cents - (dimes * 10);

    // Calculate the number of nickels
    int nickels = cents / 5;
    coins = coins + nickels;
    cents = cents - (nickels * 5);

    // Calculate the number of pennies
    int pennies = cents;  // Since each penny is worth 1 cent
    coins = coins + pennies;

    // Print the total number of coins
    printf("%d\n", coins);
}
