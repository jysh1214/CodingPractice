# [Nesting](https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/)

## Total Score 100
```c++
#include <string>
#include <vector>

int solution(string& S) {
    if (S.size() == 0) return 1;

    std::vector<bool> stack;
    for (size_t i = 0; i < S.size(); ++i) {
        if (S[i] == '(') {
            stack.push_back(true);
        }
        else {
            if (stack.size() == 0) {
                return 0;
            }
            else {
                stack.pop_back();
            }
        }
    }

    return stack.size() == 0;
}
```