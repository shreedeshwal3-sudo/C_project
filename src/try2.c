#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int minesCount, choice;
    int mines[4];   // max mines = 4
    float balance, bet, winnings, multiplier;
    char again;

    srand(time(0));

    // User enters starting balance
    printf("Enter your starting balance: ");
    scanf("%f", &balance);

    if (balance <= 0) {
        printf("Invalid balance! Exiting game.\n");
        return 0;
    }

    do 
    {
        // Select number of mines
        printf("\nChoose number of mines (2 or 4): ");
        scanf("%d", &minesCount);

        if (minesCount != 2 && minesCount != 4) 
        {
            printf("Invalid choice! Choose only 2 or 4 mines.\n");
            continue;
        }

        // Set multiplier based on mines
        if (minesCount == 2)
            multiplier = 1.5;
        else
            multiplier = 3.0;

        printf("\n====================================\n");
        printf("        MINES BETTING GAME\n");
        printf("====================================\n");
        printf("Your current balance: %.2f\n", balance);
        printf("Multiplier: %.1f\n", multiplier);

        printf("Enter your bet amount: ");
        scanf("%f", &bet);

        if (bet <= 0 || bet > balance) 
        {
            printf("Invalid bet! Try again.\n");
            continue;
        }

        // Generate mines
        for (int i = 0; i < minesCount; i++) 
        {
            int pos;
            do {
                pos = rand() % 9 + 1;
                int unique = 1;
                for (int j = 0; j < i; j++) 
                {
                    if (mines[j] == pos)
                        unique = 0;
                }
                if (unique) {
                    mines[i] = pos;
                    break;
                }
            } while (1);
        }

        printf("Choose a tile (1–9): ");
        scanf("%d", &choice);

        int hitMine = 0;
        for (int i = 0; i < minesCount; i++) 
        {
            if (choice == mines[i])
                hitMine = 1;
        }

        if (choice < 1 || choice > 9) 
        {
            printf("Invalid tile! You lose your bet.\n");
            balance -= bet;
        }
        else if (hitMine) 
        {
            printf("\n💣 BOOM! You hit a mine. You lose your bet!\n");
            balance -= bet;
        }
        else 
        {
            winnings = bet * multiplier;
            printf("\n🎉 Safe! You win %.2f!\n", winnings);
            balance += (winnings - bet);
        }

        printf("\nMines were at: ");
        for (int i = 0; i < minesCount; i++)
            printf("%d ", mines[i]);

        printf("\nYour new balance: %.2f\n", balance);

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
