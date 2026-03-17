#include <stdio.h>

int main() {
    int n, i, time = 0, smallest;
    int bt[20], at[20], pr[20];
    int remaining[20], wt[20], tat[20], ct[20];
    int complete = 0;
    float avg_wt = 0, avg_tat = 0;

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

        remaining[i] = bt[i];
    }

    while(complete != n) {
        smallest = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && remaining[i] > 0) {
                if(smallest == -1 || pr[i] < pr[smallest]) {
                    smallest = i;
                }
            }
        }

        if(smallest == -1) {
            time++;
            continue;
        }

        remaining[smallest]--;
        time++;

        if(remaining[smallest] == 0) {
            complete++;

            ct[smallest] = time;  

            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];

            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
