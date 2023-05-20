#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
int dynamic_knapsack(int[], int[], int, int);

int main() {
    int p[] = {1, 2, 5, 6};
    int w[] = {2, 3, 4, 5};

    printf("%d\n", dynamic_knapsack(w, p, 4, 8));

    return 0;
}

int dynamic_knapsack(int weights[], int values[], int n, int maxWeight) {
    int dp[n + 1][maxWeight + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = max(values[i-1] + dp[i-1][j - weights[i-1]], dp[i-1][j]);
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][maxWeight];
}