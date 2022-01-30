# [StoneWall](https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/)

## Total Score 100
```c++
#include <vector>

int solution(vector<int> &H) {
    std::vector<int> stoneH;
    int numOfStone = 0;
    for (int h : H) {
        while (stoneH.size() > 0) {
            if (h < stoneH.back()) {
                stoneH.pop_back();
                ++numOfStone;
            }
            else {
                break;
            }
        }
        if (stoneH.size() == 0 || h > stoneH.back()) {
            stoneH.push_back(h);
        }
    }

    return numOfStone + stoneH.size();
}
```