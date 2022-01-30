# [MaxCounters](https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/)

## Total Score 100
```c++
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int>& A) {
    vector<int> ans(N, 0);
    if (A.size() == 0) return ans;

    int base = 0;
    int maxCounter = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        int c = A[i];
        if (c == N + 1) { // max counter
            base = maxCounter;
        }
        else {
            ans[c - 1] = (ans[c - 1] < base) 
                ? base + 1
                : ans[c - 1] + 1;
            maxCounter = max(maxCounter, ans[c - 1]);
        }
    }

    for (auto it = ans.begin(); it != ans.end(); ++it) {
        if (*it < base) *it = base;
    }

    return ans;
}
```