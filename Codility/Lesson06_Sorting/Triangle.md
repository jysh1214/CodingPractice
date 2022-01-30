# [Triangle](https://app.codility.com/programmers/lessons/6-sorting/triangle/)

## Total Score 100
```c++
#include <algorithm>
#include <limits.h>

int solution(vector<int> &A) {
    if (A.size() < 3) return 0;

    std::sort(A.begin(), A.end());
    for (size_t i = 0; i < A.size() - 2; ++i) {
        if (A[i] <= 0) {
            continue;
        }

        uint32_t P = static_cast<uint32_t>(A[i]);
        uint32_t Q = static_cast<uint32_t>(A[i+1]);
        uint32_t R = static_cast<uint32_t>(A[i+2]);

        if (P + Q > R && 
            Q + R > P &&
            R + P > Q) {
            return 1;
        }
    }

    return 0;
}
```