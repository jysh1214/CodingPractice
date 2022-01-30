# [Brackets](https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/)

## Total Score 100
```c++
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

namespace {
    bool stackPopSuccess(vector<uint8_t>& stack, 
        const uint8_t n) {

        if (stack.size() == 0 || stack.back() != n) {
            return false;
        }
        stack.pop_back();

        return true;
    }
}

int solution(string& S) {
    if (S.size() == 0) return 1;

    // '{}' : 1, '[]' : 2, '()' : 3
    vector<uint8_t> stack;
    for (auto s : S) {
        switch (s) {
        case '{': stack.push_back(1); break;
        case '[': stack.push_back(2); break;
        case '(': stack.push_back(3); break;
        case '}':
            if (!stackPopSuccess(stack, 1))
                return 0;
            break;
        case ']': 
            if (!stackPopSuccess(stack, 2))
                return 0;
            break;
        case ')': 
            if (!stackPopSuccess(stack, 3))
                return 0;
            break;
        }
    } 

    return (stack.size() == 0) ? 1 : 0;
}
```