# [House Robber](https://leetcode.com/problems/house-robber/)

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(
                dp[i - 2] + nums[i], // rob ith house
                dp[i - 1]            // don't rob ith house
            );
        }
        
        return dp.back();
    }
};
```