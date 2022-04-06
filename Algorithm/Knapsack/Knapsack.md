# Knapsack

## 0-1 背包
```c++
int knapsack(vector<int> weights, vector<int> value, int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int j = 1; j <= N; ++j) {
        int w = weights[j - 1];
        int v = value[j - 1];
        for (int i = 1; i <= W; ++i) {
            if (w <= i) {
                dp[j][i] = max(
                    dp[j - 1][i],        // 不取
                    dp[j - 1][i - w] + v // 取
                );
            }
            else {
                dp[j][i] = dp[j - 1][i];
            }
        }
    }

    return dp[N][W];
}
```

## 完全背包
```c++
int knapsack(vector<int> weights, vector<int> value, int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int j = 1; j <= N; ++j) {
        int w = weights[j - 1];
        int v = value[j - 1];
        for (int i = 1; i <= W; ++i) {
            if (w <= i) {
                dp[j][i] = max(
                    dp[j - 1][i],    // 不取
                    dp[j][i - w] + v // 第 j 件物品再多拿一件
                );
            }
            else {
                dp[j][i] = dp[j - 1][i];
            }
        }
    }

    return dp[N][W];
}
```