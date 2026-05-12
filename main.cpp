#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Generate random page sequence
void generateRandom(int pages[], int n) {
    for(int i = 0; i < n; i++) {
        pages[i] = rand() % 10;
    }
}

// LRU Algorithm
float LRU(int pages[], int n, int size) {
    int cache[MAX], time[MAX];
    int hit = 0, miss = 0, counter = 0;

    for(int i = 0; i < size; i++) {
        cache[i] = -1;
        time[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < size; j++) {
            if(cache[j] == pages[i]) {
                hit++;
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) {
            miss++;
            int lru_index = 0;
            for(int j = 1; j < size; j++) {
                if(time[j] < time[lru_index])
                    lru_index = j;
            }
            cache[lru_index] = pages[i];
            counter++;
            time[lru_index] = counter;
        }
    }

    printf("\n--- LRU Results ---\n");
    printf("Hits = %d\nMisses = %d\nHit Ratio = %.2f\n", hit, miss, (float)hit/n);
    return (float)hit/n;
}

// FIFO Algorithm
float FIFO(int pages[], int n, int size) {
    int cache[MAX];
    int front = 0;
    int hit = 0, miss = 0;

    for(int i = 0; i < size; i++)
        cache[i] = -1;

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < size; j++) {
            if(cache[j] == pages[i]) {
                hit++;
                found = 1;
                break;
            }
        }

        if(!found) {
            cache[front] = pages[i];
            front = (front + 1) % size;
            miss++;
        }
    }

    printf("\n--- FIFO Results ---\n");
    printf("Hits = %d\nMisses = %d\nHit Ratio = %.2f\n", hit, miss, (float)hit/n);
    return (float)hit/n;
}

int main() {
    int pages[MAX];
    int n, size, choice;
    char again;

    srand(time(0));

    do {
        printf("\n===== Cache Memory Management System =====\n");
        printf("1. Manual Input\n2. Random Generate\nChoose: ");
        scanf("%d", &choice);

        printf("Enter number of pages: ");
        scanf("%d", &n);

        if(choice == 1) {
            printf("Enter page sequence:\n");
            for(int i = 0; i < n; i++) {
                scanf("%d", &pages[i]);
            }
        } else {
            generateRandom(pages, n);
            printf("Generated Sequence:\n");
            for(int i = 0; i < n; i++)
                printf("%d ", pages[i]);
            printf("\n");
        }

        printf("Enter cache size: ");
        scanf("%d", &size);

        // ================= LRU STEP-BY-STEP =================
        printf("\nStep-by-step LRU Simulation:\n");

        int cacheArr[MAX], timeArr[MAX];
        int hit = 0, miss = 0, counter = 0;

        for(int i = 0; i < size; i++) {
            cacheArr[i] = -1;
            timeArr[i] = 0;
        }

        printf("Step\tPage\tCache\t\tHit/Miss\n");

        for(int i = 0; i < n; i++) {
            int found = 0;

            for(int j = 0; j < size; j++) {
                if(cacheArr[j] == pages[i]) {
                    found = 1;
                    hit++;
                    counter++;
                    timeArr[j] = counter;
                    break;
                }
            }

            if(!found) {
                miss++;
                int lru_index = 0;
                for(int j = 1; j < size; j++) {
                    if(timeArr[j] < timeArr[lru_index])
                        lru_index = j;
                }
                cacheArr[lru_index] = pages[i];
                counter++;
                timeArr[lru_index] = counter;
            }

            printf("%d\t%d\t", i+1, pages[i]);
            for(int k = 0; k < size; k++) {
                if(cacheArr[k] != -1)
                    printf("%d ", cacheArr[k]);
                else
                    printf("- ");
            }

            if(found) printf("\tHit\n");
            else printf("\tMiss\n");
        }

        // ================= FIFO STEP-BY-STEP =================
        printf("\nStep-by-step FIFO Simulation:\n");

        int fifoCache[MAX];
        int frontPtr = 0;
        int fifoHit = 0, fifoMiss = 0;

        for(int i = 0; i < size; i++)
            fifoCache[i] = -1;

        printf("Step\tPage\tCache\t\tHit/Miss\n");

        for(int i = 0; i < n; i++) {
            int found = 0;

            for(int j = 0; j < size; j++) {
                if(fifoCache[j] == pages[i]) {
                    found = 1;
                    fifoHit++;
                    break;
                }
            }

            if(!found) {
                fifoCache[frontPtr] = pages[i];
                frontPtr = (frontPtr + 1) % size;
                fifoMiss++;
            }

            printf("%d\t%d\t", i+1, pages[i]);
            for(int k = 0; k < size; k++) {
                if(fifoCache[k] != -1)
                    printf("%d ", fifoCache[k]);
                else
                    printf("- ");
            }

            if(found) printf("\tHit\n");
            else printf("\tMiss\n");
        }

        // ================= FINAL RESULTS =================
        float lru_ratio = LRU(pages, n, size);
        float fifo_ratio = FIFO(pages, n, size);

        // Repeat option
        printf("\nDo you want to run again? (y/n): ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y');

    printf("\nProgram exited.\n");
    return 0;
}
