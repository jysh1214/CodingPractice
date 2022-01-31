# [CountSemiprimes](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/)

## Total Score 55
```c++
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

namespace {
    inline bool isPrime(const int n) {
        int limit = static_cast<int>(sqrt(n));
        for (int num = 2; num <= limit; ++num) {
            if (n % num == 0) return false;
        }

        return true;
    }
}

vector<int> solution(int N, vector<int>& P, vector<int>& Q) {
    int maxUpperBound = 0;
    for (size_t i = 0; i < Q.size(); ++i) {
        maxUpperBound = max(maxUpperBound, Q[i]);
    }

    vector<int> prime;
    for (int num = 2; num <= maxUpperBound; ++num) {
        if (isPrime(num)) prime.push_back(num);
    }

    vector<int> products;
    for (int i = 0; i < prime.size(); ++i) {
        for (int j = i; j < prime.size(); ++j) {
            products.push_back(prime[i] * prime[j]);
        }
    }
    sort(products.begin(), products.end());

    vector<int> ans;
    int count;
    for (int pq = 0; pq < P.size(); ++pq) {
        count = 0;
        for (int p = 0; p < products.size(); ++p) {
            if (products[p] >= P[pq] && products[p] <= Q[pq]) {
                ++count;
            }
            if (products[p] > Q[pq])
                break;
        }
        ans.push_back(count);
    }

    return ans;
}
```

### Comment
應該全部算完在查表比較快

## Total Score 100
```c++
#include <math.h>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

namespace {
    inline bool isSemiprime(int num) {
        int cnt = 0;
        for (int i = 2; cnt < 2 && i * i <= num; ++i) {
            while (num % i == 0) {
                ++cnt;
                num /= i;
            }
        }
        // 如能被非質數 x 整除且 num / x > 1，而 x 有因數為 y, z
        // 則 i = y, z 時會被整除
        // 此時 num 會是 num / x > 1
        // cnt 至少為 3  
        if (num > 1) {
            ++cnt;
        }
     
        return cnt == 2;
    }
}

vector<int> solution(int N, vector<int>& P, vector<int>& Q) {
    vector<int> table(N + 1, 0);
    for (int i = 2, cnt = 0; i <= N; ++i) {
        if (isSemiprime(i)) {
            ++cnt;
        }
        table[i] = cnt;
    }

    vector<int> ans;
    for (int i = 0; i < P.size(); ++i) {
        int lower = (P[i] - 1 < 0) ? 0 : P[i] - 1;
        int cnt = table[Q[i]] - table[lower];
        ans.push_back(cnt);
    }

    return ans;
}
```

### References
- [Check whether a number is semiprime or not](https://www.geeksforgeeks.org/check-whether-number-semiprime-not/)