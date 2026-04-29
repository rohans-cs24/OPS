#include <stdio.h>

int main() {
    int blocks[50], processes[50];
    int allocation[50];
    int m, n, i, j, worstIdx;

    // Input number of blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    // Input block sizes
    printf("Enter sizes of memory blocks:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &blocks[i]);
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process sizes
    printf("Enter sizes of processes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }

    // Initialize allocation
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Worst-Fit Allocation
    for (i = 0; i < n; i++) {
        worstIdx = -1;

        for (j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= processes[i]; // reduce remaining size
        }
    }

    // Output result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
