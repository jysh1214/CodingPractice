# DFS

不限於處理 `graph` 所以特別獨立一篇。
其實就是帶有 `ancestors` 資訊的遞迴。

通常會帶入兩種資訊到遞迴以求出解答:
- 參考資料: 用以找出子節點，節點分數，權重和拜訪過的點等等
- 當前狀態: 紀錄目前路徑長度，累加分數等等資訊

常見題型有:
- 找出最長或最大的路線
- 找出符合條件的所有路線

重要:
不要往 `parent` 找，一律往 `child` 找

pattern:
```c++
void dfs(const int start, // 通常會有開始節點的資訊
         /* 參考資料 1 */,
         /* 參考資料 2 */,
         /* ...       */,
         /* 當前狀態 1 */,
         /* 當前狀態 2 */,
         /* ...      */) {

    if (/* 終止條件 */) {
        // ...
        return;
    }

    // ...
}
```

## 案例 ##
- Leetcode 104. Maximum Depth of Binary Tree
    - 參考資料: linked list
    - 當前狀態: 使用 1 + dfs(...) 代表目前長度
    - 終止條件: 權重皆為 1 ，最長路徑一定是走越遠越好，走到沒有子節點為止
- Leetcode 437. Path Sum III
    - 參考資料: linked list，目標分數
    - 當前狀態: 目前累加的分數，目前找到符合條件的路線數目
    - 終止條件: 走到沒有子節點為止
- Leetcode 2192. All Ancestors of a Node in a Directed Acyclic Graph
    - 參考資料: 子節點, 拜訪過的點
    - 當前狀態: 紀錄之前的祖先
    - 終止條件: 走到沒有子節點為止