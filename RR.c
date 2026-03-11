#include <stdio.h>

struct Process {
    int pid, burst, arrival, remaining, waiting, turnaround, finish;
};

int main() {
    int n, quantum, time = 0, completed = 0;
    struct Process p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        p[i].finish = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    while (completed < n) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                done = 0;
                if (p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].remaining = 0;
                    p[i].finish = time;
                    p[i].turnaround = p[i].finish - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    completed++;
                }
            }
        }
        if (done) time++; // CPU idle, move time forward
    }

    printf("\n--- Round Robin ---\n");
    float total_wait = 0, total_turn = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d: Waiting=%d, Turnaround=%d\n", p[i].pid, p[i].waiting, p[i].turnaround);
        total_wait += p[i].waiting;
        total_turn += p[i].turnaround;
    }

    printf("\nAverage Waiting Time: %.2f", total_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turn / n);

    return 0;
}
