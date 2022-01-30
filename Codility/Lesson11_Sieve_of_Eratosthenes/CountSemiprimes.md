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