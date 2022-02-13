# [Removing Minimum Number of Magic Beans](https://leetcode.com/contest/weekly-contest-280/problems/removing-minimum-number-of-magic-beans/)

```c++
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int64_t sum = accumulate(beans.begin(), beans.end(), (int64_t)0);
        sort(beans.begin(), beans.end());

        int64_t ans = LLONG_MAX;
        for (int i = 0; i < beans.size(); ++i) {
            int64_t tmp = sum - (beans.size() - i) * beans[i];
            ans = (ans < tmp) ? ans : tmp;
        }
        
        return ans;
    }
};
```