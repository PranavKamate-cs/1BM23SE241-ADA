#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Sort by value/weight ratio (descending)
void sortByRatio(float value[], float weight[], float ratio[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swap(&ratio[j], &ratio[j + 1]);
                swap(&value[j], &value[j + 1]);
                swap(&weight[j], &weight[j + 1]);
            }
        }
    }
}

float fractionalKnapsack(int capacity, float value[], float weight[], int n) {
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    sortByRatio(value, weight, ratio, n);

    float totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += value[i] * (capacity / weight[i]);
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    float value[] = {60, 100, 120};
    float weight[] = {10, 20, 30};
    int n = sizeof(value) / sizeof(value[0]);
    int capacity = 50;

    float maxValue = fractionalKnapsack(capacity, value, weight, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
