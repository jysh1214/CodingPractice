# [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0)
            return 0;
        
        // 多增加一行一列比較好算，不用做邊界處理
        int row = text1.size() + 1;
        int col = text2.size() + 1;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int j = 1; j < row; ++j) {
            for (int i = 1; i < col; ++i) {
                if (text1[j - 1] == text2[i - 1]) {
                    dp[j][i] = dp[j - 1][i - 1] + 1;
                }
                else {
                    dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
                }
            }
        }
        
        return dp[row - 1][col - 1];
    }
};
```