#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int numberToGuess = rand() % 101;
    int userGuess = 0;
    int attempts = 5;
    printf ( "Welcome to the Number Guessing Game!" );
    printf ( "\nI have selected a number between 1 and 100. Can you guess it?" );
    printf ( "\nYou have 5 attempts to guess the number." );
    while (userGuess != numberToGuess && attempts > 0)
    {
        printf ( "\nEnter your guess: ");
        scanf ("%d", &userGuess);
        if (userGuess < numberToGuess)
        {
            printf ( "Too low! Try again.\n");
            printf ( "Attempts left: %d" ,attempts-1);
        }
        else if (userGuess > numberToGuess)
        {
            printf ( "Too high! Try again.\n");
            printf ( "Attempts left: %d" , attempts-1);
        }
        else
        {
            printf ( "Congratulations! You've guessed the number!");
        }
        attempts--;
    }
    if (attempts == 0 && userGuess != numberToGuess)
    {
        printf ( "\nSorry, you've run out of attempts. The number was %d" , numberToGuess );
    }
    return 0;
}
