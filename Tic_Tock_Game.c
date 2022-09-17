#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char char1, char char2)
{
    // For rock paper scissors . Returns 1 if Char 1 is greater than Char 2 otherwise . IF char1 == to Char 2 will return -1.
    if (char1 == char2)
    {
        return -1;
    }
    else if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }

    else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }

    else if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if  ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}
int main()
{
    int PlayerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("Welcome to the Rock, Paper, Scissors game. ");

    for (int i = 0; i < 3; i++)
    {
        // Generate player input.
        printf("Player 1's Turn : \n");
        printf("Choose 1 for Roch , 2 for Paper and 3 for scissors \n");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf("You choose %c\n", playerChar);

        // Generate computer input.
        printf("Computer's Turn : \n");
        printf("Choose 1 for Roch , 2 for Paper and 3 for scissors \n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf("CPU choose %c\n", compChar);

        //  Compare these scores...
        if (greater(compChar, playerChar) == 1)
        {
            compScore += 1;
            printf("CPU got it!\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore += 1;
            PlayerScore += 1;
            printf("It's a draw!\n");
        }
        else
        {
            PlayerScore += 1;
            printf("You Got it!\n");
        }
        printf("You: %d\n CPU: %d\n\n", PlayerScore, compScore);
    }
    if (PlayerScore > compScore)
    {
        printf("You win the game...");
    }
    else if (PlayerScore < compScore)
    {
        printf("CPU win the game...");
    }
    else 
    {
        printf("It's a drwa...\n");
    }
    
    return 0;
}