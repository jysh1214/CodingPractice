# [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/)

```c++
class Solution {
public:
    /**
     * 0 是由 5 * 2 組成, 所以要找出 5, 2 因數個數
     * 又因 2 因數遠比 5 多, 知道 5 因數個數即可
     * 10^n = 5^n * 2^n
     * 由上式可得知, 找出 5 的最大次方數並且 n 可以被整除
     * 就可以知道尾數幾個零
     * ref: https://www.justquant.com/numbertheory/highest-power-of-a-number-in-a-factorial/
     */
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
```