# [Fish](https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/)

## Total Score 100
```c++
#include <vector>

int solution(vector<int>& A, vector<int>& B) {
    std::vector<size_t> upStream;   // 0
    std::vector<size_t> downStream; // 1
    bool isEaten = false;
    for (size_t i = 0; i < A.size(); ++i) {
        if (B[i] == 0) { // up stream
            while (downStream.size() > 0) {
                size_t downFish = downStream.back();
                if (i > downFish) { // meet
                    if (A[downFish] < A[i]) { // eat
                        downStream.pop_back();
                        // upStream.push_back(i);
                    }
                    else { // be eaten
                        isEaten = true;
                        break;
                    }
                }
                else { // don't meet
                    break;
                }
            }

            if (!isEaten) upStream.push_back(i);
            isEaten = false;
        }
        else { // down stream
            while (upStream.size() > 0) {
                size_t upFish = upStream.back();
                if (i < upFish) { // meet
                    if (A[upFish] < A[i]) { // eat
                        upStream.pop_back();
                    }
                    else { // be eaten
                        isEaten = true;
                        break;
                    }
                }
                else { // don't meet
                    break;
                }
            }

            if (!isEaten) downStream.push_back(i);
            isEaten = false;
        }
    }

    return upStream.size() + downStream.size();
}
```

### Comment
其實只要做一個方向就好

### Total Score 100 (2)
```c++
#include <vector>

int solution(vector<int>& A, vector<int>& B) {
    std::vector<size_t> upStream;   // 0
    std::vector<size_t> downStream; // 1
    bool isEaten = false;
    for (size_t i = 0; i < A.size(); ++i) {
        if (B[i] == 0) { // up stream
            while (downStream.size() > 0) {
                size_t downFish = downStream.back();
                if (i > downFish) { // meet
                    if (A[downFish] < A[i]) { // eat
                        downStream.pop_back();
                        // upStream.push_back(i);
                    }
                    else { // be eaten
                        isEaten = true;
                        break;
                    }
                }
                else { // don't meet
                    break;
                }
            }

            if (!isEaten) upStream.push_back(i);
            isEaten = false;
        }
        else { // down stream
            downStream.push_back(i);
        }
    }

    return upStream.size() + downStream.size();
}
```