# [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

```c++
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> step{ 1, 2 };
        for (int i = 2; i < n; ++i) {
            step.push_back(step[i - 1] + step[i - 2]);
        }
        
        return step.back();
    }
};
```