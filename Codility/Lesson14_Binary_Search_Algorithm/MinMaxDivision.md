# [MinMaxDivision](https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/)

## Total Score 100
```c++
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

namespace {
    int calcNumOfBlocks(vector<int>& in, const int maxSum) {
        int blockSum = 0;
        int numOfBlocks = 0;
        for (auto elem : in) {
            blockSum += elem;
            if (blockSum > maxSum) {
                blockSum = elem;
                ++numOfBlocks;
            }
        }

        return numOfBlocks + 1;
    }
}

int solution(int K, int M, vector<int>& A) {
    int upperBound = accumulate(A.begin(), A.end(), 0);
    int lowerBound = *max_element(A.begin(), A.end());

    if (K >= A.size()) return lowerBound;
    if (K == 1) return upperBound;

    while (lowerBound <= upperBound) {
        int middle = (upperBound - lowerBound) / 2 + lowerBound;
        int numOfBlocks = calcNumOfBlocks(A, middle);
        if (numOfBlocks <= K) {
            upperBound = middle - 1;
        }
        else {
            lowerBound = middle + 1;
        }
    }

    return lowerBound;
}
```