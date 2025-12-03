#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int mine1, mine2, choice;
    int balance, bet;
    char playAgain;

    srand(time(0));

    printf("Enter your starting balance: ");
    scanf("%d", &balance);

    if (balance <= 0) {
        printf("Balance must be greater than 0.\n");
        return 0;
    }

    do {
        printf("\n====================================\n");
        printf("         MINES BETTING GAME\n");
        printf("====================================\n");
        printf("Your Balance: %d\n", balance);

        printf("Enter your bet amount: ");
        scanf("%d", &bet);

        if (bet <= 0 || bet > balance) {
            printf("Invalid bet amount!\n");
            continue;
        }

        mine1 = rand() % 9 + 1;
        do {
            mine2 = rand() % 9 + 1;
        } while (mine2 == mine1);

        printf("Choose a tile (1-9): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid tile! Round cancelled.\n");
            continue;
        }

        printf("\nYou selected tile %d\n", choice);

        if (choice == mine1 || choice == mine2) {
            printf(" * BOOM! You hit a mine.\n");
            printf("You lost your bet.\n");
            balance -= bet;
        } else {
            printf(" SAFE! You win.\n");
            printf("Your bet is doubled!\n");
            balance += bet;   // profit = bet (total return = bet×2)
        }

        printf("Mines were at: %d and %d\n", mine1, mine2);
        printf("Your new balance: %d\n", balance);

        if (balance <= 0) {
            printf("\nYou have no balance left. Game over!\n");
            break;
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\n====================================\n");
    printf("         FINAL BALANCE: %d\n", balance);
    printf("====================================\n");

    return 0;
}
