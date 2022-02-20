# [Power of Four](https://leetcode.com/problems/power-of-four/)

```c++
namespace {
    bool inline isPowOfTwo(int n) {
        return (n & (n - 1)) == 0;
    }
    
    bool oddPosOne(int n) {
        int pos = 0;
        while (n != 1) {
            n >>= 1;
            ++pos;
        }
        return (pos + 1) % 2 == 1;
    }
}

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        return isPowOfTwo(n) && oddPosOne(n);
    }
};
```