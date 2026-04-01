#include <stdio.h>

#define MAX 50

typedef struct {
    int pid;
    int arrival;
    int burst;
    int deadline;
    int completed;
} Process;

int main() {
    int n, time = 0, completed = 0;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Deadline: ");
        scanf("%d", &p[i].deadline);

        p[i].completed = 0;
    }

    printf("\nExecution Order:\n");

    while (completed < n) {
        int idx = -1;
        int earliest_deadline = 9999;

        // Find process with earliest deadline among arrived ones
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].completed == 0) {
                if (p[i].deadline < earliest_deadline) {
                    earliest_deadline = p[i].deadline;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            printf("P%d -> ", p[idx].pid);
            time += p[idx].burst;
            p[idx].completed = 1;
            completed++;
        } else {
            // If no process has arrived yet
            time++;
        }
    }

    printf("END\n");

    return 0;
}
