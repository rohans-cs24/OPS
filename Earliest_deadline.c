#include <stdio.h>

#define MAX 10
#define SIM_TIME 30

typedef struct {
    int pid;
    int burst;          // C
    int period;         // T
    int deadline;       // D (relative)
    int remaining;
    int next_release;
    int abs_deadline;   // absolute deadline
} Task;

int main() {
    int n;
    Task t[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Input
    for (int i = 0; i < n; i++) {
        t[i].pid = i + 1;

        printf("\nTask %d\n", i + 1);

        printf("Burst Time: ");
        scanf("%d", &t[i].burst);

        printf("Deadline: ");
        scanf("%d", &t[i].deadline);

        printf("Period: ");
        scanf("%d", &t[i].period);


        t[i].remaining = 0;
        t[i].next_release = 0;
        t[i].abs_deadline = 0;
    }

    printf("\nExecution Timeline:\n");

    for (int time = 0; time < SIM_TIME; time++) {

        // Release jobs
        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining = t[i].burst;
                t[i].abs_deadline = time + t[i].deadline;
                t[i].next_release += t[i].period;
            }
        }

        int idx = -1;
        int earliest_deadline = 99999;

        // Choose earliest deadline
        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (t[i].abs_deadline < earliest_deadline) {
                    earliest_deadline = t[i].abs_deadline;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            printf("T%d ", t[idx].pid);
            t[idx].remaining--;
        } else {
            printf("Idle ");
        }

        // Check deadline miss
        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0 && time + 1 > t[i].abs_deadline) {
                printf("\n Deadline Missed by T%d at time %d\n", t[i].pid, time + 1);
                t[i].remaining = 0; // discard job
            }
        }
    }

    printf("\n");
    return 0;
}
