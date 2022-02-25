# [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## 1.
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

## 2. DIY
```c++
namespace {
    int lowerBound(const vector<int>& nums, const int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
    
    int upperBound(const vector<int>& nums, const int target) {
        /**
         * r = nums.size() 而非 r = nums.size() - 1 的原因 :
         * 當 nums = [1], target = 1 時，
         * 如果 r = nums.size() - 1，答案會是 [0, -1](upper 算出來會多減 1)
         * 所以使用 r = nums.size()
         */
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + (r - 1)) / 2;
            if (nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{ -1, -1 };
        if (target < nums.front() || target > nums.back())
            return vector<int>{ -1, -1 };
        
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target) - 1;
        
        if (lower == nums.size() || nums[lower] != target)
            return vector<int>{ -1, -1 };
        
        return vector<int>{ lower, upper };
    }
};
```