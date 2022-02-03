# [Assign Cookies](https://leetcode.com/problems/assign-cookies/)

## 1.
```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int sit = 0;
        for (int i = 0; i < g.size(); ++i) {
            while (sit < s.size() && s[sit] < g[i]) {
                ++sit;
            }
            if (sit == s.size()) {
                break;
            }
            else { // feed
                ++count;
                ++sit;
            }
        }
        
        return count;
    }
};
```

## 2.
```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) ++child;
            ++cookie;
        }
        
        return child;
    }
};
```