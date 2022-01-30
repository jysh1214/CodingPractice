# [OddOccurrencesInArray](https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/)

## Total Score 100
```c++
#include <algorithm>

int solution(vector<int>& A) {
    std::sort(A.begin(), A.end());
    for (size_t i = 0; i < A.size(); i += 2) {
        if (A[i] != A[i + 1]) {
            return A[i];
        }
    }

    return *A.end();
}
```