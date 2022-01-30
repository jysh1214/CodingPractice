# [MinAvgTwoSlice](https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/)

## Total Score 100
```c++
#include <float.h>

int solution(vector<int>& A) {
    float minAvg = FLT_MAX;
    float twoAvg;
    float threeAvg;
    int minPos = 0;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        twoAvg = static_cast<float>(A[i] + A[i+1]) / 2;
        if (twoAvg < minAvg) {
            minAvg = twoAvg;
            minPos = i;
        }

        if (i + 2 < A.size()) {
            threeAvg = static_cast<float>(A[i] + A[i+1] + A[i+2]) / 3;
            if (threeAvg < minAvg) {
                minAvg = threeAvg;
                minPos = i;
            }
        }
    }

    return minPos;
}
```