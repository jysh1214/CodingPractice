# [Two Sum](https://leetcode.com/problems/two-sum/)

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                return vector<int>{ m[target - nums[i]], i };
            }
            else {
                m[nums[i]] = i;
            }
        }
        
        return vector<int>{ 0, 1 };
    }
};
```