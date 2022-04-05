# [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

1. Accept

左閉右閉。

```c++
namespace {
    int lowerBound(const vector<int>& nums, const int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        return (left < nums.size() && nums[left] == target) 
            ? left 
            : -1;
    }
    
    int upperBound(const vector<int>& nums, const int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        return (left - 1 < nums.size() && nums[left - 1] == target) 
            ? left - 1
            : -1;
    }
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{ -1, -1 };
        if (target < nums.front() || target > nums.back())
            return vector<int>{ -1, -1 };
        
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        
        return vector<int>{ lower, upper };
    }
};
```

2. Accept

右邊界改用 `right` 去做判斷。

```c++
namespace {
    int lowerBound(const vector<int>& nums, const int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        return (left < nums.size() && nums[left] == target) 
            ? left 
            : -1;
    }
    
    int upperBound(const vector<int>& nums, const int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        /**
         * 右邊界改用 right 去做判斷
         */
        return (right >= 0 && nums[right] == target)
            ? right
            : -1;
    }
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{ -1, -1 };
        if (target < nums.front() || target > nums.back())
            return vector<int>{ -1, -1 };
        
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        
        return vector<int>{ lower, upper };
    }
};
```

3. Accept

因為數列是排序過的，先判斷 `target` 在不在範圍內，就不用考慮邊界問題。

```c++
namespace {
    int lowerBound(const vector<int>& nums, const int target) {
        if (target < nums.front() || target > nums.back())
            return -1;
        
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        return nums[left] == target ? left : -1;
    }
    
    int upperBound(const vector<int>& nums, const int target) {
        if (target < nums.front() || target > nums.back())
            return -1;
        
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        return nums[right] == target ? right : -1;
    }
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{ -1, -1 };
        if (target < nums.front() || target > nums.back())
            return vector<int>{ -1, -1 };
        
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        
        return vector<int>{ lower, upper };
    }
};
```

4. Accept

直接使用 `std::upper_bound` 和 `std::lower_bound`。

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{ -1, -1 };
        if (target < nums.front() || target > nums.back())
            return vector<int>{ -1, -1 };
        
        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        if (lower == nums.size() || nums[lower] != target)
            return vector<int>{ -1, -1 };
        
        return vector<int>{ lower, upper };
    }
};
```