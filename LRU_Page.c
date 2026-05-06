                                                                                                                                              #include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, pos, pageFaults = 0;
    int counter = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in frames
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter; // update recent use
                found = 1;
                break;
            }
        }

        // If page not found → page fault
        if(!found) {
            // Find least recently used frame
            pos = 0;
            for(j = 1; j < f; j++) {
                if(time[j] < time[pos]) {
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            pageFaults++;
        }

        // Print frames
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
