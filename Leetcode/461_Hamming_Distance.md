# [Hamming Distance](https://leetcode.com/problems/hamming-distance/)

```c++
namespace {
    int numOfOne(int x) {
        int count = 0;
        while (x) {
            x &= x - 1;
            ++count;
        }
        return count;
    }
}

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        return numOfOne(diff);
    }
};
```