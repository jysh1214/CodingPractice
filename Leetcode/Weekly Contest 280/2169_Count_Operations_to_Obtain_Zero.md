# [Count Operations to Obtain Zero](https://leetcode.com/contest/weekly-contest-280/problems/count-operations-to-obtain-zero/)

```c++
namespace {
    int sub2zero(int large, int small) {
        if (small == 1) return large;
        if (large == 0 || small == 0) return 0;
        if (large == small) return 1;
        if (large - small >= small) {
            large = large - small;
        }
        else {
            int tmp = large - small;
            large = small;
            small = tmp;
        }
        return 1 + sub2zero(large, small);
    }
}

class Solution {
public:
    int countOperations(int num1, int num2) {
        int large = max(num1, num2);
        int small = min(num1, num2);
        
        return sub2zero(large, small);
    }
};
```