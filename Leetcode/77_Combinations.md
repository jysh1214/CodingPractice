# [Combinations](https://leetcode.com/problems/combinations/)

```c++
namespace {
    void comb(vector<vector<int>>& ans, vector<int>& combtmp, int& count, int start, int n, int k) {
        if (count == k) {
            ans.push_back(combtmp);
            return;
        }
        
        for (int i = start; i < n; ++i) {
            combtmp[count] = i + 1;
            ++count;
            comb(ans, combtmp, count, i + 1, n, k);
            --count;
        }
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combtmp(k, 0);
        int count = 0;
        int start = 0;
        comb(ans, combtmp, count, start, n, k);
        
        return ans;
    }
};
```