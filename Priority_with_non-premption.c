#include <stdio.h>

int main() {
    int n, i, j, pos;
    int at[20], bt[20], pr[20];
    int ct[20], wt[20], tat[20];
    int temp;
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
    }

    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i+1; j < n; j++) {
            if(pr[j] < pr[pos]) {
                pos = j;
            }
        }

        temp = pr[i]; pr[i] = pr[pos]; pr[pos] = temp;
        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = at[i]; at[i] = at[pos]; at[pos] = temp;
    }

    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        total_tat+= tat[i];
        wt[i] = tat[i] - bt[i];
        total_wt+= wt[i];
    }

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }


    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);
    return 0;
}
