# [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/)

```c++
class Solution {
public:
    Solution(vector<int>& nums) {
        orig = nums;
    }
    
    vector<int> reset() {
        return orig;
    }
    
    //  Fisher-Yates Shuffle
    vector<int> shuffle() {
        vector<int> shuf = orig;
        if (shuf.empty()) return shuf;
        
        int n = shuf.size();
        for (int i = 0; i < n; ++i) {
            swap(shuf[i], shuf[rand() % (i + 1)]);
        }
        
        return shuf;
    }
private:
    vector<int> orig;
};
```