#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int mine1, mine2, choice;
    float balance, bet, winnings;
    char again;

    srand(time(0));

    // Take starting balance from user
    printf("Enter your starting balance: ");
    scanf("%f", &balance);

    if (balance <= 0) {
        printf("Invalid balance! Exiting game.\n");
        return 0;
    }

    do 
    {
        printf("\n====================================\n");
        printf("        MINES BETTING GAME\n");
        printf("====================================\n");
        printf("Your current balance: %.2f\n", balance);

        printf("Enter your bet amount: ");
        scanf("%f", &bet);

        if (bet <= 0 || bet > balance) 
        {
            printf("Invalid bet! Try again.\n");
            continue;
        }

        // Random mines
        mine1 = rand() % 9 + 1;
        do {
            mine2 = rand() % 9 + 1;
        } while (mine2 == mine1);

        printf("Choose a tile (1–9): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) 
        {
            printf("Invalid tile! You lose your bet.\n");
            balance -= bet;
        }
        else if (choice == mine1 || choice == mine2) 
        {
            printf("\n💣 BOOM! You hit a mine. You lose your bet!\n");
            balance -= bet;
        }
        else 
        {
            winnings = bet * 1.5;
            printf("\n🎉 Safe! You win %.2f!\n", winnings);
            balance += (winnings - bet);
        }

        printf("Mines were at: %d and %d\n", mine1, mine2);
        printf("Your new balance: %.2f\n", balance);

        if (balance <= 0) 
        {
            printf("\nYou have no money left. Game over.\n");
            break;
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\n====================================\n");
    printf("      FINAL BALANCE: %.2f\n", balance);
    printf("====================================\n");

    return 0;
}
