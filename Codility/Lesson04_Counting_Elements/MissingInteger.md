# [MissingInteger](https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/)

## Total Score 100
```c++
#include <algorithm>

int solution(vector<int>& A) {
    A.push_back(0);
    std::sort(A.begin(), A.end());
    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i] <= 0) continue;
        if (A[i] - A[i-1] > 1) {
            return A[i-1] + 1;
        }
    }

    return std::max(1, A.back() + 1);
}
```