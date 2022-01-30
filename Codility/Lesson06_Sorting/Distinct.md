# [Distinct](https://app.codility.com/programmers/lessons/6-sorting/distinct/)

## Total Score 100
```c++
#include <set>

int solution(vector<int>& A) {
    std::set<int> s;
    for (auto elem : A) {
        s.insert(elem);
    }

    return s.size();
}
```