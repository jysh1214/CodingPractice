# Sliding Window

注意 `window` 的縮小條件。

```c++
while (/* 滿足 window 擴張條件 */) {
    // window 擴張
    ++right;
    // ...
    while (/* 觸發 window 縮小條件 */) {
        // window 縮小
        ++left;
        // ...
    }
}
```

## 案例 ##
- 2134. Minimum Swaps to Group All 1's Together II: 循環的 `sliding window`，注意 `window` 擴張條件