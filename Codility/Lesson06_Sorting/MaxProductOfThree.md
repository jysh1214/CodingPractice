# [MaxProductOfThree](https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/)

## Total Score 100
```c++
#include <algorithm>

int solution(vector<int> &A) {
    std::sort(A.begin(), A.end());
    
    int maxVal = std::max(
        A.back() * (*(A.end() - 2)) * (*(A.end() - 3)),
        A[0] * A[1] * A.back()
    );

    return maxVal;
}
```