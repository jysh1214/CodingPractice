# [Dominator](https://app.codility.com/programmers/lessons/8-leader/dominator/)

## Total Score 100
```c++
#include <vector>

using namespace std;

int solution(vector<int>& A) {
    int candicate = 0;
    int count = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (count == 0) candicate = i;
        if (A[i] == A[candicate]) {
            ++count;
        }
        else {
            --count;
        }
    }
    
    count = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == A[candicate]) ++count;
    }

    return count > static_cast<int>(A.size() / 2) 
        ? candicate 
        : -1;
}
```