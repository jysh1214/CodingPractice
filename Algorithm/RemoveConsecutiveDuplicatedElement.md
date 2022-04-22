# Remove Consecutive Duplicated Element

```c++
template<typename T>
std::vector<T> removeDuplicated(std::vector<T>& input) {
    std::vector<T> ans;
    int p = -1;
    for (T i : input) {
        if (ans.empty() || ans[p] != i) {
            ans.push_back(i);
            ++p;
        }
    }
        
    return ans;
}
```