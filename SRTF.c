#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[MAX], at[MAX], bt[MAX], rt[MAX];
    int ct[MAX], tat[MAX], wt[MAX];
    int completed = 0, time = 0, min_rt, shortest = -1;
    int found;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // remaining time = burst time initially
    }

    printf("\nGantt Chart:\n| ");

    while (completed != n) {
        // Find process with min remaining time among arrived processes
        min_rt = INT_MAX;
        found = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
                found = 1;
            }
        }

        if (!found) {
            // CPU idle
            printf("idle | ");
            time++;
            continue;
        }

        rt[shortest]--;
        printf("P%d | ", pid[shortest]);
        time++;

        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    printf("\n\n");
    printf("%-6s %-10s %-10s %-10s %-10s %-10s\n",
           "PID", "AT", "BT", "CT", "TAT", "WT");
    printf("-------------------------------------------------------\n");

    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        printf("P%-5d %-10d %-10d %-10d %-10d %-10d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f\n", avg_tat / n);
    printf("Average WT  = %.2f\n", avg_wt / n);

    return 0;
}
