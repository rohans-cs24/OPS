#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k;
    int pageFaults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n\n");

    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            pageFaults++;

            int empty = -1;
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frames[empty] = pages[i];
            }
            else {
                    3

                int farthest = -1, replaceIndex = -1;

                for(j = 0; j < f; j++) {
                    int nextUse = 9999;

                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }

                    if(nextUse > farthest) {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }

                frames[replaceIndex] = pages[i];
            }
        }

        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
