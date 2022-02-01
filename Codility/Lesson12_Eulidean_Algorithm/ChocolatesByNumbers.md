# [ChocolatesByNumbers](https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/)

## Total Score 75
```c++
#include <vector>

int solution(int N, int M) {
    vector<bool> chocolates(N, false);
    int count = 0;
    for (int i = 0;; i = (i + M) % N) {
        if (chocolates[i]) {
            break;
        }
        else {
            chocolates[i] = true;
            ++count;
        }
    }

    return count;
}
```

### Comment
太慢，應直接使用公式解。

## Total Score 100
```c++
#include <vector>
#include <limits.h>

using namespace std;

namespace {
    uint64_t gcd(uint64_t a, uint64_t b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    inline uint64_t lcm(uint64_t a, uint64_t b) {
        return (a / gcd(a, b)) * b;
    }
}

int solution(int N, int M) {
    return static_cast<int>(lcm(N, M) / M);
}
```