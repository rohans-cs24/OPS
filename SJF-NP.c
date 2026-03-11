#include <stdio.h>

struct Process {
    int pid, at, bt, wt, tt, ct; // Added arrival time and completion time
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(int i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &p[i].bt);
    }

    int completed = 0, time = 0;
    int isCompleted[n];
    for(int i=0; i<n; i++) isCompleted[i] = 0;

    while(completed != n) {
        int idx = -1;
        int minBT = 1e9;

        // Find process with shortest burst among arrived processes
        for(int i=0; i<n; i++) {
            if(p[i].at <= time && isCompleted[i] == 0) {
                if(p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].wt = time - p[idx].at;
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tt = p[idx].ct - p[idx].at;
            isCompleted[idx] = 1;
            completed++;
        } else {
            time++; // If no process has arrived yet, move time forward
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTT\tCT\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tt, p[i].ct);
    }

    return 0;
}
