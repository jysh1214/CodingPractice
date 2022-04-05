# Binary Search

思想很簡單，重點在細節裡:
- 使用左閉右閉 `[left, right]` 寫法比較容易理解
- 注意使用找左邊界和右邊界的 pattern
- 判斷題目要找哪種邊界

找左邊界 pattern:
```c++
int left = /* 左閉條件 */;
int right = /* 右閉條件 */;

while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) { // 往左收斂
        right = mid - 1;
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else if (nums[mid] > target) {
        right = mid - 1;
    }
}

return left;
```

找右邊界 pattern:
```c++
int left = /* 左閉條件 */;
int right = /* 右閉條件 */;

while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) { // 往右收斂
        left = mid + 1;
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else if (nums[mid] > target) {
        right = mid - 1;
    }
}

return left - 1; // 注意
```

## 實例 ## 
- 704. Binary Search: 找特定目標，不用找邊界
- 34. Find First and Last Position of Element in Sorted Array: 第一個出現為左邊界，最後出現為右邊界
- 69. Sqrt(x): 最後會收斂在右邊界
- 