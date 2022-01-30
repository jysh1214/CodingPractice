# [FrogRiverOne](https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/)

## Total Score 100
```c++
#include <set>

using namespace std;

namespace {
    bool include(set<int>& a, set<int>& b) {
        for (auto elem : a) {
            if (b.find(elem) == b.end()) {
                return false;
            }
        }

        return true;
    }
}

int solution(int X, vector<int> &A) {
    set<int> neededLeaves;
    for (int i = 1; i <= X; ++i) {
        neededLeaves.insert(i);
    }

    set<int> leaves;
    for (int i = 0; i < A.size(); ++i) {
        int leave = A[i];
        leaves.insert(leave);

        if (leaves.size() >= X) {
            if (include(neededLeaves, leaves)) {
                return i;
            }
        }
    }

    return -1;
}
```