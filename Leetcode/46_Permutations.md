# [Permutations](https://leetcode.com/problems/permutations/)

```c++
namespace {
    void perm(vector<int>& nums, int start, vector<vector<int>>& ans) {
        if (start == nums.size()) return;
        if (start == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            perm(nums, start + 1, ans);
            swap(nums[start], nums[i]);
        }
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums, 0, ans);
        return ans;
    }
};
```