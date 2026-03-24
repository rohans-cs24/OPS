----------------------MULTILEVEL SCHEDULING------------------------------
#include <stdio.h>
#include <string.h>

struct process {
    int pid;
    int bt;
    int wt;
    int tat;
    int ct;
    char type[10]; // "sys" or "user"
};

// FCFS with start time
void fcfs(struct process p[], int n, int start_time) {
    int i;

    if (n == 0) return;

    p[0].wt = start_time;
    p[0].ct = p[0].wt + p[0].bt;
    p[0].tat = p[0].ct;

    for(i = 1; i < n; i++) {
        p[i].wt = p[i-1].ct;
        p[i].ct = p[i].wt + p[i].bt;
        p[i].tat = p[i].ct;
    }
}

// Display
void display(struct process p[], int n, char name[]) {
    int i;
    float total_wt = 0, total_tat = 0;

    printf("\n%s Queue:\n", name);
    printf("PID\tBT\tWT\tCT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].bt, p[i].wt, p[i].ct, p[i].tat);

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    if(n > 0) {
        printf("Average WT = %.2f\n", total_wt / n);
        printf("Average TAT = %.2f\n", total_tat / n);
    }
}

int main() {
    int n, i;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct process all[n], sys[n], user[n];
    int sys_count = 0, user_count = 0;

    // Input
    for(i = 0; i < n; i++) {
        all[i].pid = i + 1;

        printf("\nProcess P%d\n", all[i].pid);

        printf("Enter Burst Time: ");
        scanf("%d", &all[i].bt);

        printf("Enter Queue Type (sys/user): ");
        scanf("%s", all[i].type);

        // Separate into queues
        if(strcmp(all[i].type, "sys") == 0) {
            sys[sys_count++] = all[i];
        } else {
            user[user_count++] = all[i];
        }
    }

    // Execute System Queue first
    fcfs(sys, sys_count, 0);

    // Get last completion time
    int last_ct = 0;
    if(sys_count > 0)
        last_ct = sys[sys_count - 1].ct;

    // Execute User Queue next
    fcfs(user, user_count, last_ct);

    // Display
    display(sys, sys_count, "System");
    display(user, user_count, "User");

    printf("\nExecution Order: System → User\n");

    return 0;
}
	
