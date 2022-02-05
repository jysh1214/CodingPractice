# [347_Top_K_Frequent_Elements](https://leetcode.com/problems/top-k-frequent-elements/)

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int maxCount = 0;
        for (int n : nums) {
            if (count.find(n) != count.end()) {
                ++count[n];
            }
            else {
                count[n] = 1;
            }
            maxCount = max(maxCount, count[n]);
        }
        
        // 按照出現次數裝桶
        // 同一總次數可能有不同數字
        // 這些數字出現次數頻率一樣
        vector<vector<int>> buckets(maxCount + 1);
        for (auto& p : count) {
            buckets[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        bool done = false;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (auto c : buckets[i]) {
                ans.push_back(c);
                if (ans.size() == k) {
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        
        return ans;
    }
};
```