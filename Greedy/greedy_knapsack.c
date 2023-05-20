#include <stdio.h>

int greedy_knapsack(int[], int[], int, int);

int main() {
    int p[] = {10, 5, 15, 7, 6, 18, 3};
    int w[] = {2, 3, 5, 7, 1, 4, 1};

    printf("%d\n", greedy_knapsack(w, p, 7, 15));

    return 0;
}

int greedy_knapsack(int weights[], int values[], int n, int maxWeight) {
    float marginalValues[n];
    int maxValue = 0;
    int curWeight = 0;
    
    for (int i = 0; i < n; i++) {
        marginalValues[i] = (float)values[i] / weights[i];
    }

    for (int i = 0; i < n; i++) {
        if (curWeight == maxWeight)
            break;

        int maxIndex = -1;
        float curMaxValue = 0.0;
        int availableWeight = maxWeight - curWeight;
        for (int j = 0; j < n; j++) {
            if (weights[j] <= availableWeight && marginalValues[j] > curMaxValue) {
                curMaxValue = marginalValues[j];
                maxIndex = j;
            }
        }

        if (maxIndex != -1) {
            curWeight = curWeight + weights[maxIndex];
            maxValue = maxValue + values[maxIndex];

            weights[maxIndex] = maxWeight + 1;
        }

        printf("Current Value: %d, Current Weight: %d\n", maxValue, curWeight);
    }

    return maxValue;
}