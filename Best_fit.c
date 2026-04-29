#include <stdio.h>

int main() {
    int blocks[50], processes[50];
    int allocation[50];
    int m, n;

    // Input number of blocks
    printf("Enter number of blocks: ");
    scanf("%d", &m);

    // Input block sizes
    printf("Enter sizes of blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blocks[i]);
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process sizes
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
        allocation[i] = -1; // initialize as not allocated
    }

    // Best-Fit Allocation
    for (int i = 0; i < n; i++) {
        int bestIndex = -1;

        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (bestIndex == -1 || blocks[j] < blocks[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blocks[bestIndex] -= processes[i]; // reduce available size
        }
    }

    // Output result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
