# [BinaryGap](https://app.codility.com/programmers/lessons/1-iterations/binary_gap/)

## Total Score 100
```c++
int solution(int N) {
    bool findFirstOne = (N % 2 > 0);
    int lastOne = 1;
    int maxGap = 0;
    int cnt = 1;
    while ((N >> 1) > 0) {
        ++cnt;
        N >>= 1;
        if (N % 2 > 0) {
            if (findFirstOne) {
                maxGap = std::max(maxGap, cnt - lastOne - 1);
                lastOne = cnt;
            }
            else {
                findFirstOne = true;
                lastOne = cnt;
            }
        }
    }

    return maxGap;
}
```

