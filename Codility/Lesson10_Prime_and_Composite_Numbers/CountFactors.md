# [CountFactors](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/)

## Total Score 100
```c++
#include <math.h>

int solution(int N) {
    int q = static_cast<int>(sqrt(N));
    int cnt = 0;
    for (int i = 1; i <= q; ++i) {
        if (N % i == 0) cnt += 2;
    }

    if (q * q == N) --cnt;

    return cnt;
}
```