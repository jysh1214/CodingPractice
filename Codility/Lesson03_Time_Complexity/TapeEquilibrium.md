# [TapeEquilibrium](https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/)

## Total Score 100
```c++
#include <algorithm>
#include <limits.h>
#include <numeric>

int solution(vector<int> &A) {
    int rsum = std::accumulate(A.begin(), A.end(), 0);
    int lsum = 0;
    int minDiff = INT_MAX;
    for (size_t p = 0; p < A.size() - 1; ++p) {
        rsum -= A[p];
        lsum += A[p];
        minDiff = std::min(minDiff, abs(lsum - rsum));
    }

    return minDiff;
}
```