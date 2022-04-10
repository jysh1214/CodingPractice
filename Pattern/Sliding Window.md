# Sliding Window

注意縮小 `window` 的條件

```c++
int right = 0;
int left = 0;
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