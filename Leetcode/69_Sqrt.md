# [Sqrt](https://leetcode.com/problems/sqrtx/)

## 1.
```c++
class Solution {
public:
    int mySqrt(int x) {
        // let y = sqrt(x), y belong to [1, x]
        if (x == 0) return 0;
        int upperBound = x;
        int lowerBound = 1;
        // 用 8 帶入可知，最後收斂時，
        // upperBound 再減一即為答案
        while (lowerBound <= upperBound) {
            int mid = lowerBound + (upperBound - lowerBound) / 2;
            int sqrt = x / mid;
            if (mid == sqrt) {
                return mid;
            }
            else if (mid > sqrt) {
                upperBound = mid - 1;
            }
            else if (mid < sqrt) {
                lowerBound = mid + 1;
            }  
        }
        
        return upperBound;
    }
};
    
```