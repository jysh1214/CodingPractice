# [Number of Provinces](https://leetcode.com/problems/number-of-provinces/)

```c++
namespace {
    bool inline isNeighbor(vector<vector<int>>& isConnected, int m, int n) {
        return isConnected[m][n] == 1 && isConnected[n][m] == 1;
    }
    
    void dfs(vector<vector<int>>& isConnected, int n, unordered_set<int>& visited) {
        for (int i = 0; i < isConnected[0].size(); ++i) {
            if (visited.find(i) != visited.end()) {
                continue;
            }
            if (i != n && isNeighbor(isConnected, n, i)) {
                visited.insert(i);
                dfs(isConnected, i, visited);
            }
        }
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int row = isConnected.size();
        int col = isConnected[0].size();
        
        if (row == 0 || col == 0) return 0;
        
        int numOfProvinces = 0;
        unordered_set<int> visited;
        for (int j = 0; j < row; ++j) {
            if (visited.find(j) != visited.end()) {
                continue;
            }
            dfs(isConnected, j, visited);
            ++numOfProvinces;
        }
        
        return numOfProvinces;
    }
};
```