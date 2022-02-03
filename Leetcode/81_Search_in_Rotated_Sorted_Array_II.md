# [81_Search_in_Rotated_Sorted_Array_II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

## 1.
```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] == nums[l]) {
                ++l;
            }
            else if (nums[mid] <= nums[r]) {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else if (nums[mid] > nums[l]) {
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        
        return false;
    }
};
```