#include <stdio.h>

int main() {
    int state[5] = {0};   // 0 = Thinking, 1 = Eating
    int choice, left, right;

    for(int i = 0; i < 5; i++) {

        printf("\nPhilosopher %d\n", i + 1);
        printf("1. Think\n");
        printf("2. Eat\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        left = (i + 4) % 5;   // left neighbor
        right = (i + 1) % 5;  // right neighbor

        switch(choice) {

            case 1:
                state[i] = 0;
                printf("Philosopher %d is Thinking\n", i + 1);
                break;

            case 2:
                if(state[left] == 1 || state[right] == 1) {
                    printf("Fork unavailable! Neighbors are Eating\n");
                } else {
                    state[i] = 1;
                    printf("Philosopher %d is Eating\n", i + 1);
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
