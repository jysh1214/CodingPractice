# DFS

```c++
void dfs(Graph g, Node node) 
{
    if (node.visited == true)
        return;

    node.visited = true;
    for (Node n : getNeighbors(g, node)) {
        dfs(g, n);
    }
}
```