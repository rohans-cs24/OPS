#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main() {
    int n, i, j;
    int tickets[MAX], totalTickets = 0;
    int winner, cumulative;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of tickets for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process P%d: ", i + 1);
        scanf("%d", &tickets[i]);
        totalTickets += tickets[i];
    }

    printf("\nTotal Tickets = %d\n", totalTickets);

    srand(time(0));

    printf("\nLottery Scheduling Order:\n");

    for(i = 0; i < n; i++) {
        winner = rand() % totalTickets;
        cumulative = 0;

        for(j = 0; j < n; j++) {
            cumulative += tickets[j];
            if(winner < cumulative) {
                printf("Cycle %d: Process P%d selected (Ticket %d)\n",
                        i + 1, j + 1, winner);
                break;
            }
        }
    }

    return 0;
}
