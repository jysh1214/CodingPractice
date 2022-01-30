# [MaxDoubleSliceSum](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/)

## Total Score 61
```c++
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int solution(vector<int>& A) {
    if (A.size() <= 3) return 0;

    vector<int> candidates{ 0 }; // X:0, Y:1, Z:2
    int maxVal = 0;
    int minVal = A[1];
    for (size_t i = 2; i < A.size() - 1; ++i) {
        int old_min = minVal;
        minVal = std::min(minVal, A[i]);
        if (maxVal + A[i] - minVal < 0) {
            candidates.push_back(maxVal);
            maxVal += (A[i] - minVal);
        }
        else {
            if (A[i] < 0) candidates.push_back(maxVal);
            maxVal = std::max(maxVal + old_min + A[i] - minVal, A[i]);
        }
    }

    for (int elem : candidates) {
        maxVal = std::max(maxVal, elem);
    }

    return maxVal;
}
```

## Total Score 100
```c++
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

int solution(vector<int>& A) {
    if (A.size() <= 3) return 0;
    
    int maxVal = 0;
    vector<int> forwardMax(A.size(), 0);
    for (int i = 1; i < A.size() - 1; ++i) {
        forwardMax[i + 1] = std::max(
            forwardMax[i] + A[i], 0
        );
        maxVal = std::max(maxVal, A[i]);
    }

    if (maxVal <= 0) return 0;

    vector<int> reverseMax(A.size(), 0);
    for (int i = A.size() - 2; i >= 1; --i) {
        reverseMax[i - 1] = std::max(
            reverseMax[i] + A[i], 0
        );
    }

    maxVal = 0;
    for (int i = 1; i < A.size() - 1; ++i) {
        maxVal = std::max(
            forwardMax[i] + reverseMax[i],
            maxVal
        );
    }

    return maxVal;
}
```