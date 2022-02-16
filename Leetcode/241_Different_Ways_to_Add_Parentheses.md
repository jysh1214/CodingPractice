# [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/)

```c++
namespace {
    unordered_map<string, vector<int>> cache;
}

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if (cache.find(expression) != cache.end()) {
            return cache[expression];
        }
        for (int i = 0; i < expression.size(); ++i) {
            char op = expression[i];
            if (!isdigit(op)) {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, expression.size()));
                for (int l : left) {
                    for (int r : right) {
                        if (op == '+') {
                            ans.push_back(l + r);
                            cache[expression].push_back(l + r);
                        }
                        else if (op == '-') {
                            ans.push_back(l - r);
                            cache[expression].push_back(l - r);
                        }
                        else if (op == '*') {
                            ans.push_back(l * r);
                            cache[expression].push_back(l * r);
                        }
                    }
                }
            }
        }
        if (ans.size() == 0) ans.push_back(stoi(expression));
        
        return ans;
    }
};
```