# [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        dp[0][0] = grid[0][0];
        for (int j = 0; j < row; ++j) {
            for (int i = 0; i < col; ++i) {
                if (i == 0 && j == 0) {
                    continue;
                }
                
                int y0 = max(j - 1, 0);
                int x0 = max(i - 1, 0);
                if (y0 != j && x0 != i) {
                    dp[j][i] = min(dp[y0][i], dp[j][x0]) + grid[j][i];
                }
                else if (y0 == j) {
                    dp[j][i] = dp[j][x0] + grid[j][i];
                }
                else if (x0 == i) {
                    dp[j][i] = dp[y0][i] + grid[j][i];
                }
            }
        }
        
        return dp[row - 1][col - 1];
    }
};
```