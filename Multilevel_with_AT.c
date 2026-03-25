
//------------------Multilevel Scheduling with AT------------------

#include <stdio.h>
#include <string.h>

struct process {
    int pid;
    int at;   
    int bt;  
    int wt;  
    int tat; 
    int ct;   
    char type[10]; 
};

// Sort processes
void sort_by_at(struct process p[], int n) {
    int i, j;
    struct process temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// FCFS
void fcfs(struct process p[], int n, int start_time) {
    int i;

    if (n == 0) return;


    if(start_time < p[0].at)
        start_time = p[0].at;

    p[0].wt = start_time - p[0].at;
    p[0].ct = start_time + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;

    for(i = 1; i < n; i++) {
        int current_time = p[i-1].ct;

        if(current_time < p[i].at)
            current_time = p[i].at;

        p[i].wt = current_time - p[i].at;
        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
    }
}

// Display 
void display(struct process p[], int n, char name[]) {
    int i;
    float total_wt = 0, total_tat = 0;

    printf("\n%s Queue:\n", name);
    printf("PID\tAT\tBT\tWT\tCT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].wt, p[i].ct, p[i].tat);

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

    for(i = 0; i < n; i++) {
        all[i].pid = i + 1;

        printf("\nProcess P%d\n", all[i].pid);

        printf("Enter Arrival Time: ");
        scanf("%d", &all[i].at);

        printf("Enter Burst Time: ");
        scanf("%d", &all[i].bt);

        printf("Enter Queue Type (sys/user): ");
        scanf("%s", all[i].type);

        if(strcmp(all[i].type, "sys") == 0) {
            sys[sys_count++] = all[i];
        } else {
            user[user_count++] = all[i];
        }
    }


    sort_by_at(sys, sys_count);
    sort_by_at(user, user_count);

    fcfs(sys, sys_count, 0);

    int last_ct = 0;
    if(sys_count > 0)
        last_ct = sys[sys_count - 1].ct;

    fcfs(user, user_count, last_ct);

    // Display results
    display(sys, sys_count, "System");
    display(user, user_count, "User");

    printf("\nExecution Order: System → User\n");

    return 0;
}
