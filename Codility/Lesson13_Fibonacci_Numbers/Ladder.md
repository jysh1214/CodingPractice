# [Ladder](https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/)

## Total Score 100
```c++
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

vector<int> solution(vector<int>& A, vector<int>& B) {
    vector<int> ans;
    vector<uint64_t> dp{ 1, 2 };
    int dpi = 2;
    for (int i = 0; i < A.size(); ++i) {
        int mod = pow(2, B[i]);
        if (dpi <= A[i]) {
            for (; dpi <= A[i]; ++dpi) {
                dp.push_back(dp[dpi - 1] + dp[dpi - 2]);
            }
        }
        ans.push_back(static_cast<int>(dp[A[i] - 1] % mod));
    }

    return ans;
}
```