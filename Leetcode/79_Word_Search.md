# [Word Search](https://leetcode.com/problems/word-search/)

```c++
namespace {
    void backtracking(vector<vector<char>>& board,
                      string target,
                      int pos,
                      int j,
                      int i,
                      bool& findWord,
                      vector<vector<bool>>& visited) {
        
        if (visited[j][i] == true) return;
        if (board[j][i] != target[pos]) return;
        if (pos == target.size() - 1 && board[j][i] == target[pos]) {
            findWord = true;
            return;
        }
        
        int row = board.size();
        int col = board[0].size();
        
        int x0 = max(i - 1, 0);
        int x1 = min(i + 1, col - 1);
        int y0 = max(j - 1, 0);
        int y1 = min(j + 1, row - 1);
        
        visited[j][i] = true;
        if (x0 != i) {
            backtracking(board, target, pos + 1, j, x0, findWord, visited);
        }
        if (x1 != i) {
            backtracking(board, target, pos + 1, j, x1, findWord, visited);
        }
        if (y0 != j) {
            backtracking(board, target, pos + 1, y0, i, findWord, visited);
        }
        if (y1 != j) {
            backtracking(board, target, pos + 1, y1, i, findWord, visited);
        }
        visited[j][i] = false;
    }
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        if (row == 0 || col == 0) return false;
        
        bool findWord = false;
        char front = word[0];
        int pos = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int j = 0; j < row; ++j) {
            for (int i = 0; i < col; ++i) {
                if (board[j][i] == front) {
                    backtracking(board, word, pos, j, i, findWord, visited);
                }
                if (findWord) break;
            }
        }
        
        return findWord;
    }
};
```