#include <stdio.h>

typedef struct {
    int id;
    int burst;
    int period;
    int next_deadline;
    int remaining;
} Process;

int main() {
    int n, hyperPeriod = 1;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
        printf("Process %d Period: ", i + 1);
        scanf("%d", &p[i].period);
        p[i].next_deadline = p[i].period;
        p[i].remaining = p[i].burst;
        hyperPeriod *= p[i].period; // naive LCM approximation
    }

    printf("\nExecution Timeline:\n");

    for (int time = 0; time < hyperPeriod; time++) {
        int chosen = -1;

        // Select process with earliest deadline (shortest period = highest priority)
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                if (chosen == -1 || p[i].period < p[chosen].period) {
                    chosen = i;
                }
            }
        }

        if (chosen != -1) {
            printf("Time %d: P%d\n", time, p[chosen].id);
            p[chosen].remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }

        // Reset tasks at their period boundaries
        for (int i = 0; i < n; i++) {
            if ((time + 1) % p[i].period == 0) {
                p[i].remaining = p[i].burst;
            }
        }
    }

    return 0;
}
