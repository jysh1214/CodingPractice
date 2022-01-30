# [PassingCars](https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/)

## Total Score 100
```c++
#include <vector>
#include <ctype.h>

namespace {
    uint32_t merge(std::vector<int>& a, 
        std::vector<int>& b, 
        std::vector<int>& c) {

        c.clear();
        int asize = a.size();
        int bsize = b.size();
        std::vector<int>::iterator ait = a.begin();
        std::vector<int>::iterator bit = b.begin();
        uint32_t passingPairs = 0;

        while (ait != a.end() && bit != b.end()) {
            if (*ait < *bit) {
                passingPairs += bsize;
                c.push_back(*ait);
                ++ait;
                --asize;
            }
            else {
                c.push_back(*bit);
                ++bit;
                --bsize;
            }
        }

        if (ait == a.end()) {
            while (bit != b.end()) {
                c.push_back(*bit);
                ++bit;
            }
        }

        if (bit == b.end()) {
            while (ait != a.end()) {
                c.push_back(*ait);
                ++ait;
            }
        }

        return passingPairs;
    }

    uint32_t mergeSort(std::vector<int>& input) {
        if (input.size() == 1) return 0;

        int middle = input.size() / 2;
        std::vector<int> left(input.begin(), input.begin() + middle);
        std::vector<int> right(input.begin() + middle, input.end());
        uint32_t l = mergeSort(left);
        uint32_t r = mergeSort(right);
        uint32_t both = merge(left, right, input);

        return l + r + both;
    }
}

int solution(vector<int>& A) {
    if (A.size() == 0) return 0;
    uint32_t ans = mergeSort(A);
    return ans > 1000000000 ? -1 : static_cast<int>(ans);
}
```