# [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)


## 1. 
```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        uint32_t sum = 0;
        for (int elem : nums) {
            sum += elem;
        }
        if (sum % 2 == 1) return false;
        int target = static_cast<int>(sum / 2);
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        for (int j = 1; j <= nums.size(); ++j) {
            for (int i = 1; i <= target; ++i) {
                int value = nums[j - 1];
                if (value <= i) {
                    dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - value] + value);
                }
                else {
                    dp[j][i] = dp[j - 1][i];
                }
                
                if (dp[j][i] == target) return true;
            }
        }
        
        return false;
    }
};
```

## 2. 
```c++
class Solution {
public:
    int inline sum(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        
        return sum;
    }
    
    bool canPartition(vector<int>& nums) {
        int sumVal = sum(nums);
        if (sumVal % 2 == 1) {
            return false;
        }
        
        int halfSum = sumVal / 2;
        std::vector<bool> dp(halfSum + 1, false);
        
        dp[0] = true;
        for (auto num : nums) {
            for (int i = halfSum; i >= num; --i) {
                if ((dp[i - num])) {
                    dp[i] = true;
                }
            }
        }
        
        return dp[halfSum];
    }
};
```