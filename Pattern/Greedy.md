# Greedy

貪心法為 `DP` 的特例，用貪心法能做的，用 `DP` 也能做。
兩者最大的差別為，貪心法每一步選擇局最佳解，讓結果是全域最佳解。

找出規律，做出最佳解是最難的部分。

貪心法有兩種題型:
- 分配
- 區間: 較難的題型，通常需要找出適合的排序方法

## 分配 ##



## 區間 ##
通常會給一個包含區間頭尾資訊的陣列(或是自己生成出來)，
通常解題有三個步驟:
1. 找出正確的比較涵式
2. 排序
3. 迭代計算要的資訊

```c++
auto comp = [](){
    // 重點在此
};

sort(array.begin(), array.end(), comp);
for (/* 迭代 */) {
    // ...
}
```

區間問題又分為多種題型:
1. 找出重疊區間
2. 找出不重疊區間
3. 合併重疊區間
4. 移除重疊區間
5. 找出重疊區間交集
6. 


## 案例 ##
分配:


區間:
- 435. Non-overlapping Intervals
- 452. Minimum Number of Arrows to Burst Balloons
- 2136. Earliest Possible Day of Full Bloom: 合併重疊區間為最小，因為在生長時間時，可以同時種植其他植物，因此高 `growTime` 優先種植，如果 `growTime` 一樣，則挑 `plantTime` 短的優先種植

## References ##
- [Greedy for Beginners [Problems | Sample solutions]](https://leetcode.com/discuss/general-discussion/669996/Greedy-for-Beginners-Problems-or-Sample-solutions/578298)