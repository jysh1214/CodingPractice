# [PermCheck](https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/)

## Total Score 100
```c++
#include <algorithm>

int solution(vector<int> &A) {
    std::sort(A.begin(), A.end());
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] != i + 1) {
            return 0;
        } 
    }

    return 1;
}
```