# [Candy](https://leetcode.com/problems/candy/)

## 1.
```c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) return ratings.size();
        
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        for (int i = ratings.size() - 1; i >= 1; --i) {
            if (ratings[i - 1] > ratings[i]) {
                if (candies[i - 1] <= candies[i]) {
                    candies[i - 1] = candies[i] + 1;
                }
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
```