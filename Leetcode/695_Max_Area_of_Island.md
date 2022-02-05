# [695_Max_Area_of_Island](https://leetcode.com/problems/max-area-of-island/)

```c++
namespace {
    int dfs(vector<vector<int>>& grid, int j, int i) {
        int row = grid.size();
        int col = grid[0].size();
        
        if (grid[j][i] == 0) return 0;
        
        // 簡單把訪問過的點設成 0
        // 防止無限迴圈
        // 紀錄訪問過的點也可以
        grid[j][i] = 0;
        
        int area = 1;
        int x0 = max(i - 1, 0);
        int x1 = min(i + 1, col - 1);
        int y0 = max(j - 1, 0);
        int y1 = min(j + 1, row - 1);
        
        if (x0 != i) {
            area += dfs(grid, j, x0);
        }
        if (x1 != i) {
            area += dfs(grid, j, x1);
        }
        if (y0 != j) {
            area += dfs(grid, y0, i);
        }
        if (y1 != j) {
            area += dfs(grid, y1, i);
        }
        
        return area;
    }
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        if (row == 0 || col == 0)
            return 0;
        
        int maxArea = 0;
        for (int j = 0; j < row; ++j) {
            for (int i = 0; i < col; ++i) {
                if (grid[j][i] == 1) {
                    maxArea = max(maxArea, dfs(grid, j, i));
                }
            }
        }
        
        return maxArea;
    }
};
```