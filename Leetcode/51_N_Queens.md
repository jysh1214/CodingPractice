# [N-Queens](https://leetcode.com/problems/n-queens/)

```c++
namespace {
    bool check(int j, int i, vector<int>& diag) {
        for (int d = 0; d < diag.size(); ++d) {
            if (diag[d] != -1) {
                if (i - d == 0) return false;
                if (j - diag[d] == 0) return false;
                if (abs(i - d) == abs(j - diag[d]))
                    return false;
            }
        }
        
        return true;
    }
    
    void backtracking(vector<string>& board,
                      int j,
                      vector<int>& diag,
                      vector<vector<string>>& ans) {
        
        if (j == board.size()) {
            ans.push_back(board);
            return;
        }
        
        for (int i = 0; i < board[0].size(); ++i) {
            if (check(j, i, diag)) {
                board[j][i] = 'Q';
                diag[i] = j;
                backtracking(board, j + 1, diag, ans);
                board[j][i] = '.';
                diag[i] = -1;
            }
        }
        
        return;
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string emptyRow = ".";
        for (int i = 1; i < n; ++i) {
            emptyRow += ".";
        }
        vector<string> board(n, emptyRow);
        int r = 0;
        vector<int> diag(n, -1);
        backtracking(board, r, diag, ans);
        
        return ans;
    }
};
```