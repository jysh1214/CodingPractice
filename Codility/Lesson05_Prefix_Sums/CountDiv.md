# [CountDiv](https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/)

## Total Score 100
```c++
int solution(int A, int B, int K) {
    int ans = B / K - A / K;
    if (A % K == 0) ++ans;
    return ans;
}
```