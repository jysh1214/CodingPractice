# [MaxSliceSum](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/)

## Total Score 100
```c++
#include <vector>
#include <algorithm>

int solution(vector<int>& A) {
    vector<int> candidates;
    int maxVal = A[0];
    for (size_t i = 1; i < A.size(); ++i) {
        if (maxVal + A[i] < 0) {
            candidates.push_back(maxVal);
            maxVal = A[i];
        }
        else {
            if (A[i] < 0) candidates.push_back(maxVal);
            maxVal = std::max(maxVal + A[i], A[i]);
        }
    }

    for (int c : candidates) {
        maxVal = std::max(maxVal, c);
    }

    return maxVal;
}
```