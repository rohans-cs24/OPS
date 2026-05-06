
#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k = 0, pageFaults = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames with -1
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already exists in frames
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found → Page Fault
        if(!found) {
            frames[k] = pages[i];
            k = (k + 1) % f; // FIFO replacement
            pageFaults++;
        }

        // Print current frame state
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
