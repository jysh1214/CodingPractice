# [MinPerimeterRectangle](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/)

## Total Score 100
```c++
#include <math.h>

int solution(int N) {
    int a = static_cast<int>(sqrt(N));
    while (N % a != 0) {
        --a; // ++a 邏輯也對，但比較慢沒有過測試時間
    }
    int b = N / a;

    return 2 * (a + b);   
}
```

### Comment
用找質數的思維去想