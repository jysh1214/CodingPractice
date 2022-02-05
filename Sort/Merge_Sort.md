# Merge Sort

```c++
void merge(vector<int>& result, vector<int>& nums, int ls, int le, int rs, int re) 
{
    int l = ls;
    int r = rs;
    while (l <= le && r <= re) {
        if (nums[l] <= nums[r]) {
            result.push_back(nums[l]);
            ++l;
        }
        else {
            result.push_back(nums[r]);
            ++r;
        }
    }
    
    while (l <= le) {
        result.push_back(nums[l]);
        ++l;
    }
    
    while (r <= re) {
        result.push_back(nums[r]);
        ++r;
    }
}

void mergesort(vector<int>& nums, int start, int end)
{
    if (start >= end) return;
    
    int mid = (start + end) / 2;
    mergesort(nums, start, mid);
    mergesort(nums, mid + 1, end);
    
    vector<int> tmp;
    merge(tmp, nums, start, mid, mid + 1, end);
    
    for (int i = start; i <= end; ++i) {
        nums[i] = tmp[i - start];
    }
}
```