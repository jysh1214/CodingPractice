# [Minimum Operations to Make the Array Alternating](https://leetcode.com/contest/weekly-contest-280/problems/minimum-operations-to-make-the-array-alternating/)

```c++
namespace {
    void findTop2(pair<int, int>& maxp, pair<int, int>& secp, unordered_map<int, int>& m) {
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second >= maxp.second) {
                secp = maxp;
                maxp = make_pair(it->first, it->second);
            }
            else if (it->second >= secp.second) {
                secp = make_pair(it->first, it->second);
            }
        }
    }
}

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> evenFreq;
        unordered_map<int, int> oddFreq;

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                ++evenFreq[nums[i]];
            }
            else {
                ++oddFreq[nums[i]];
            }
        }
        
        int numOfEven = ceil(static_cast<float>(nums.size()) / 2);
        int numOfOdd = nums.size() / 2;
        
        pair<int, int> max_ed = make_pair(0, 0);
        pair<int, int> sec_ed = make_pair(0, 0);
        findTop2(max_ed, sec_ed, evenFreq);
        
        pair<int, int> max_od = make_pair(0, 0);
        pair<int, int> sec_od = make_pair(0, 0);
        findTop2(max_od, sec_od, oddFreq);
        
        if (max_ed.first == max_od.first) {
            return (numOfEven - max_ed.second + numOfOdd - sec_od.second) < (numOfEven - sec_ed.second + numOfOdd - max_od.second) 
                ? numOfEven - max_ed.second + numOfOdd - sec_od.second
                : numOfEven - sec_ed.second + numOfOdd - max_od.second;
        }
        
        return numOfEven - max_ed.second + numOfOdd - max_od.second;
    }
};
```