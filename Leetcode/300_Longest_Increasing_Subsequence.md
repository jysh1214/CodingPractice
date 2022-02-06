# [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int maxLen = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // 必定可以接收比自己數小的 subsequence
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};
```