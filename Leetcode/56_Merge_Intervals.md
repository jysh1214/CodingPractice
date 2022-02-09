#  [Merge Intervals](https://leetcode.com/problems/merge-intervals/)

## 1.
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto p : intervals) {
            ++m[p[0]];
            --m[p[1]];
        }
        
        vector<vector<int>> ans;
        int count = 0;
        int start;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (count == 0) {
                start = it->first;
            }
            count += it->second; 
            if (count == 0) {
                ans.push_back(vector<int>{ start, it->first });
            }
        }
        
        return ans;
    }
};
```
