# [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)

```c++
class Solution {
public:
    Solution(vector<int>& w) {
        cdf = w;
        partial_sum(cdf.begin(), cdf.end(), cdf.begin());
    }
    
    int pickIndex() {
        int pos = (rand() % cdf.back()) + 1;
        return lower_bound(cdf.begin(), cdf.end(), pos) - cdf.begin();
    }
private:
    vector<int> cdf;
};

```