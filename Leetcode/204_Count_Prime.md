# [Count Primes](https://leetcode.com/problems/count-primes/)

```c++
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int count = n - 1 - 1; // 不包含自己和1
        vector<bool> isPrime(n, true);
        isPrime[1] = false;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i] == false) {
                continue;
            }
            for (int j = 2 * i; j < n; j += i) {
                if (isPrime[j]) { // 防止重複扣
                    isPrime[j] = false;
                    --count;  
                }
            }
        }
        
        return count;
    }
};
```