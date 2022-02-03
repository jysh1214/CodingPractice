# [Two_Sum_II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

## 1.
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] < target) {
                ++l;
            }
            else if (numbers[l] + numbers[r] > target) {
                --r;
            }
            else {
                break;
            }
        }
        
        return vector<int>{ l + 1, r + 1 };
    }
};
```