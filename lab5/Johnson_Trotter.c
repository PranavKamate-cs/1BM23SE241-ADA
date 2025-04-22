#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT -1
#define RIGHT 1

// Function to print the permutation
void printPermutation(int* perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Function to find the largest mobile integer
int getMobile(int* perm, int* dir, int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int nextIndex = i + dir[perm[i] - 1];
        if (nextIndex >= 0 && nextIndex < n && perm[i] > perm[nextIndex]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
            }
        }
    }
    return mobile;
}

// Function to get the position of the mobile integer
int getPosition(int* perm, int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == mobile)
            return i;
    }
    return -1;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main Johnson-Trotter algorithm
void johnsonTrotter(int n) {
    int* perm = (int*)malloc(n * sizeof(int));
    int* dir = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    for (int i = 1; i < tgamma(n + 1); i++) {
        int mobile = getMobile(perm, dir, n);
        if (mobile == 0)
            break;

        int pos = getPosition(perm, n, mobile);
        int d = dir[mobile - 1];

        swap(&perm[pos], &perm[pos + d]);
        swap(&dir[perm[pos] - 1], &dir[perm[pos + d] - 1]);

        // Reverse direction of all elements greater than mobile
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile) {
                dir[perm[i] - 1] = -dir[perm[i] - 1];
            }
        }

        printPermutation(perm, n);
    }

    free(perm);
    free(dir);
}

int main() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
