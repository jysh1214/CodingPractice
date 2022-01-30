# [Peaks](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/)

## Total Score 81
```c++
#include <vector>

using namespace std;

namespace {
    inline bool isPeak(const vector<int>& A, const int i) {
        if (i == 0 || i == A.size() - 1) return false;
        return (A[i] > A[i - 1] && A[i] > A[i + 1]);
    }
}

int solution(vector<int>& A) {
    int maxNumOfBlocks = 0;
    for (int numOfBlocks = 1; numOfBlocks <= A.size(); ++numOfBlocks) {
        if (A.size() % numOfBlocks != 0) {
            continue;
        }
        
        int blockSize = A.size() / numOfBlocks;
        // check each blocks
        bool includePeak = true;
        for (int blocksid = 0; blocksid < numOfBlocks; ++blocksid) {
            bool blockInclPeak = false;
            for (int b = 0; b < blockSize; ++b) {
                int index =  blocksid * blockSize + b;
                if (isPeak(A, index)) {
                    blockInclPeak = true;
                    break;
                }
            }

            if (!blockInclPeak) {
                includePeak = false;
                break;
            }
        }
        
        if (!includePeak) {
            return maxNumOfBlocks;
        }
        else {
            maxNumOfBlocks = std::max(maxNumOfBlocks, numOfBlocks);
        }
    }

    return maxNumOfBlocks;
}
```
### Comment
原因:
切三份不行，不代表四份不行，要計算全部因數

三份: O O X X|O O O O|X X O O

四份: O O X|X O O|O O X|X O O

## Total Score 100
```c++
#include <vector>

using namespace std;

namespace {
    inline bool isPeak(const vector<int>& A, const int i) {
        if (i == 0 || i == A.size() - 1) return false;
        return (A[i] > A[i - 1] && A[i] > A[i + 1]);
    }
}

int solution(vector<int>& A) {
    int maxNumOfBlocks = 0;
    for (int numOfBlocks = 1; numOfBlocks <= A.size(); ++numOfBlocks) {
        if (A.size() % numOfBlocks != 0) {
            continue;
        }
        
        int blockSize = A.size() / numOfBlocks;
        // check each blocks
        bool includePeak = true;
        for (int blocksid = 0; blocksid < numOfBlocks; ++blocksid) {
            bool blockInclPeak = false;
            for (int b = 0; b < blockSize; ++b) {
                int index =  blocksid * blockSize + b;
                if (isPeak(A, index)) {
                    blockInclPeak = true;
                    break;
                }
            }

            if (!blockInclPeak) {
                includePeak = false;
                break;
            }
        }

        if (includePeak) {
            maxNumOfBlocks = std::max(maxNumOfBlocks, numOfBlocks);
        }
    }

    return maxNumOfBlocks;
}
```