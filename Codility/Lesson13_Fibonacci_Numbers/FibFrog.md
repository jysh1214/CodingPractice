# [FibFrog](https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/)

## Total Score 100
```c++
#include <vector>

using namespace std;

namespace {
    void clacFab(vector<int>& fab, const int upper) {
        fab.push_back(1);
        fab.push_back(2);
        for (int i = 2;; ++i) {
            int fabVal = fab[i - 1] + fab[i - 2];
            if (fabVal <= upper) {
                fab.push_back(fabVal);
            }
            else {
                break;
            }
        }
    }
}

int solution(vector<int>& A) {
    A.insert(A.begin(), 1); // first: 讓計算位置公式統一
    A.push_back(1);         // bank: 不用計算到岸距離

    vector<int> fab;
    clacFab(fab, A.size());

    if (A.size() - 1 == fab.back())
        return 1;

    vector<int> step(A.size(), A.size() + 1);
    step[0] = 0;
    for (int curPos = 1; curPos < A.size(); ++curPos) {
        if (A[curPos] != 1) {
            continue;
        }
        for (int f : fab) {
            int dist = curPos - f;
            if (dist >= 0) {
                /**
                 * 包含兩個訊息: dist 為費波納係數和更新步數
                 * 到 dist 的步數先前有被算到, 即 dist 為費波納係數
                 */
                if (step[dist] + 1 < step[curPos]) {
                    step[curPos] = step[dist] + 1;
                }
            }
            else {
                break;
            }
        }
    }

    return (step.back() < A.size() + 1) ? step.back() : -1;
}
```