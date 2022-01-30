# [EquiLeader](https://app.codility.com/programmers/lessons/8-leader/equi_leader/)

## Total Score 100
```c++
#include <vector>
#include <unordered_map>

namespace {
    inline float div(const size_t a, const size_t b) {
        return static_cast<float>(a) / b;
    }
}

int solution(vector<int> &A) {
    std::unordered_map<int, size_t> freq;
    for (size_t i = 0; i < A.size(); ++i) {
        ++freq[A[i]];
    }

    int leader = A[0];
    size_t maxShowTimes = 0;
    for (auto f : freq) {
        if (f.second > maxShowTimes) {
            maxShowTimes = f.second;
            leader = f.first;
        }
    }

    size_t lefShowTimes = 0;
    size_t rightShowTimes = maxShowTimes;
    size_t leftSize = 0;
    size_t rightSize = A.size();
    int count = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        ++leftSize;
        --rightSize;
        if (A[i] == leader) {
            ++lefShowTimes;
            --rightShowTimes;
        }
        
        if (div(lefShowTimes, leftSize) > 0.5
            && div(rightShowTimes, rightSize) > 0.5)
        {
            ++count;
        }
    }

    return count;
}
```