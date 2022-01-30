# [MaxProfit](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/)

## Total Score 100
```c++
#include <vector>
#include <algorithm>
#include <limits.h>

int solution(vector<int>& A) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int price : A) {
        minPrice = min(price, minPrice); 
        maxProfit = max(price - minPrice, maxProfit);
    }

    return maxProfit;
}
```