# [Combination Sum](https://leetcode.com/problems/combination-sum/)

```c++
namespace {
    void backtracking(vector<vector<int>>& ans, 
                      vector<int>& components,
                      vector<int>& candidates,
                      int start,
                      int sum, 
                      const int target) {
        
        if (sum == target) {
            ans.push_back(components);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            int c = candidates[i];
            if (sum + c <= target) {
                components.push_back(c);
                backtracking(ans, components, candidates, i, sum + c, target);
                components.pop_back();
            }
            else {
                break;
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> components;
        backtracking(ans, components, candidates, 0, 0, target);
        
        return ans;
    }
};
```