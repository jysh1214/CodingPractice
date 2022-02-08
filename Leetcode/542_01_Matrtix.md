# [01 Matrix](https://leetcode.com/problems/01-matrix/)

```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row, vector<int>(col, row + col));
        for (int j = 0; j < row; ++j) {
            for (int i = 0; i < col; ++i) {
                if (mat[j][i] == 0) {
                    dp[j][i] = 0;
                }
                else {
                    if (j > 0) {
                        dp[j][i] = min(dp[j][i], dp[j - 1][i] + 1);
                    }
                    if (i > 0) {
                        dp[j][i] = min(dp[j][i], dp[j][i - 1] + 1);
                    }
                }
            }
        }
        
        for (int j = row - 1; j >= 0; --j) {
            for (int i = col - 1; i >= 0; --i) {
                if (mat[j][i] == 0) {
                    dp[j][i] = 0;
                }
                else {
                    if (j < row - 1) {
                        dp[j][i] = min(dp[j][i], dp[j + 1][i] + 1);
                    }
                    if (i < col - 1) {
                        dp[j][i] = min(dp[j][i], dp[j][i + 1] + 1);
                    }
                }
            }
        }
        
        return dp;
    }
};
```