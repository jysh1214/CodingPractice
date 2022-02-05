# [Kth_Large_Element_in_an_Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

```c++
namespace {
    int quickSelect(vector<int>& nums, int start, int end) {
        int l = start + 1;
        int r = end;
        int pivot = nums[start];
        while (true) { // l == r 時可以繼續找，只是不會 swap
            while (l < end && nums[l] <= pivot) {
                ++l;
            }
            while (start < r && nums[r] >= pivot) {
                --r;
            }
            if (l >= r) {
                break;
            }
            swap(nums[l], nums[r]);
        }
        // 單純排序下方也可以
        // 但當 l == r 時繼續找才會找到對的名次
        // while (l < r) {
        //     while (l < end && nums[l] <= pivot) {
        //         ++l;
        //     }
        //     while (r > start && nums[r] >= pivot) {
        //         --r;
        //     }
        //     if (l < r) {
        //        swap(nums[l], nums[r]); 
        //     }
        // }
        swap(nums[start], nums[r]);
        
        return r;
    }
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int nth = quickSelect(nums, start, end);
            if (nth == target) {
                return nums[nth];
            }
            else if (nth < target) {
                start = nth + 1;
            } 
            else if (nth > target) {
                end = nth - 1;
            }
        }
        
        return nums[start];
    }
};
```