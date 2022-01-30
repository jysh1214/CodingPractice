# [CyclicRotation](https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/)

## Total Score 100
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
    void rotate(vector<int> &A) {
        size_t end = A.size() - 1;
        for (size_t i = 0; i < end; ++i) {
            swap(A[i], A[end]);
        }
    }
}

vector<int> solution(vector<int> &A, int K) {
    vector<int> ans = A;
    if (A.size() == 0 || K % A.size() == 0) 
        return ans;

    for (int i = 0; i < K; ++i) {
        rotate(ans);
    }

    return ans;
}
```