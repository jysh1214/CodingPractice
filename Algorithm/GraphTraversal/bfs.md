# BFS

```c++
void bfs(Graph g, Node node) 
{
    deque<Node> queue{ node };
    while (!queue.empty()) {
        Node n = queue.front();
        for (Node m : getNieghbors(g, n)) {
            if (visited(m) == false) {
                queue.push_back(m);
                visited(m) = true;
            }
        }
        queue.pop_front();
    }
}
```