# Quick Sort

```c++
void quicksort(vector<int>& nums, int start, int end)
{
    if (start >= end) return;
    
    int l = start;
    int r = end;
    int pivot = nums[l];
    while (l < r) {
        while (l < r && nums[r] >= pivot) {
            --r;
        }
        nums[l] = nums[r];
        while (l < r && nums[l] <= pivot) {
            ++l;
        }
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    quicksort(nums, start, l - 1);
    quicksort(nums, l + 1, end);
}
```