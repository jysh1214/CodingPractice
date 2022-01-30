# [NumberOfDiscIntersections](https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/)

## Total Score 100
```c++
#include <vector>
#include <algorithm>

int solution(vector<int> &A) {
    // let j > i, and A[i] + A[j] >= j - i
    // => A[i] + i >= j - A[j]
    std::vector<int64_t> ilist;
    std::vector<int64_t> jlist;
    for (size_t i = 0; i < A.size(); ++i) {
        ilist.push_back(A[i] + i);
        jlist.push_back(i - A[i]);
    }
    std::sort(ilist.begin(), ilist.end());
    std::sort(jlist.begin(), jlist.end());

    int64_t sum = 0;
    size_t j = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        while (j < A.size() && ilist[i] >= jlist[j]) {
            sum += static_cast<int64_t>(j - i);
            if (sum > 10000000) return -1;
            ++j;
        }
    }

    return static_cast<int>(sum);
}
```