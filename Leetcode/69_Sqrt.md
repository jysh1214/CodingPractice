# [Sqrt](https://leetcode.com/problems/sqrtx/)

## 1. Accept

會收斂到 `upper bound`，使用找右邊界的 pattern。

```c++
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int left = 1;
        int right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sqrt = x / mid; // 若開根號非整數則 sqrt 一定會大於 mid，收斂在右邊界
            if (sqrt == mid) {
                return mid;
            } else if (sqrt > mid) {
                left = mid + 1;
            } else if (sqrt < mid) {
                right = mid - 1;
            }
        }
        
        return left - 1;
    }
};
```