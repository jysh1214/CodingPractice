# [NailingPlanks](https://app.codility.com/programmers/lessons/14-binary_search_algorithm/nailing_planks/)

## Total Score 50
```c++
#include <vector>

using namespace std;

namespace {
    bool check(vector<bool>& in) {
        for (bool b : in) {
            if (b == false)
                return false;
        }
        return true;
    }
}

int solution(vector<int>& A, vector<int>& B, vector<int>& C) {
    int numOfNail = 0;
    vector<bool> nailed(A.size(), false);
    for (auto nailPos : C) {
        ++numOfNail;
        for (int i = 0; i < A.size(); ++i) {
            int start = A[i];
            int end = B[i];
            if (nailPos >= start && nailPos <= end) {
                nailed[i] = true;
            }
            if (check(nailed)) 
                return numOfNail;
        }
    }

    return -1;
}
```