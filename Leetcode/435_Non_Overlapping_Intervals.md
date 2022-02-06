# [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

## 1.
```c++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto sortedByEnd = [](vector<int>& a, vector<int>& b){
            if (b[1] > a[1]) {
                return true;
            }
            // small interval has a higher priority
            else if (b[1] == a[1] && b[0] < a[0]) {
                return true;
            }
            return false;
        };
        
        sort(intervals.begin(), intervals.end(), sortedByEnd);
        
        int removeCount = 0;
        int prev = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[prev][1]) {
                ++removeCount;
            }
            else {
                prev = i;
            }
        }
        
        return removeCount;
    }
};
```