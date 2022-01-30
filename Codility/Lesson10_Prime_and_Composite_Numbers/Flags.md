# [Flags](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/)

## Total Score 100
```c++
#include <vector>

using namespace std;

namespace {
    inline bool isPeak(vector<int>& A, const int i) {
        if (i == 0 || i == A.size() - 1) return false;
        return (A[i] > A[i + 1] && A[i] > A[i - 1]);
    }
}

int solution(vector<int> &A) {
    if (A.size() < 3) return 0;

    int flags = 1;
    for (; flags < A.size(); ++flags) {
        int cnt = flags;
        for (int i = 1; i < A.size() - 1; ++i) {
            if (isPeak(A, i)) {
                --cnt;
                // maybe next flags could be better
                if (cnt == 0) break;

                i += flags - 1;
            }            
        }

        if (cnt > 0) {
            --flags;
            break;
        }
    }

    return flags;
}
```