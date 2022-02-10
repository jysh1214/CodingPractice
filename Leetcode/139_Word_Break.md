# [Word Break](https://leetcode.com/problems/word-break/)

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            for (string word : wordDict) {
                int start = i + 1 - word.size();
                if (start >= 0 && s.substr(start, word.size()) == word) {
                    dp[i + 1] = dp[i + 1] || dp[(i + 1) - word.size()];
                }
            }
        }
        
        return dp.back();
    }
};
```