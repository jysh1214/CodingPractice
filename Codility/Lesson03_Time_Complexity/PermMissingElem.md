# [PermMissingElem](https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/)

## Total Score 100
```c++
#include <vector>

int solution(vector<int>& A) {
    int sum = 0;
    for (int num = 1; num <= A.size() + 1; ++num) {
        sum ^= num;
    }

    for (int a : A) {
        sum ^= a;
    }

    return sum;
}
```