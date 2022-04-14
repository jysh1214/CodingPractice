# Chain Reactions #

1. WRONG

這種寫法代表，最小分數的 prev 所有路徑與自己合併，
但應該只合併到 prev 的路線才對。

```c++
#include <stdio.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace {
    template <typename T>
    void inline readBatchData(std::vector<T>& in, const int size) {
        T tmp;
        for (int i = 0; i < size; ++i) {
            std::cin >> tmp;
            in.push_back(tmp);
        }
    }
    
    void inline findPrevModules(std::vector<std::vector<int>>& prev, 
                                const std::vector<int>& point) {
        for (int i = 1; i < point.size(); ++i) {
            prev[point[i]].push_back(i);
        }
    }
    
    long long trigger(const int start, 
                      const std::vector<std::vector<int>>& prev, 
                      const std::vector<long long>& fun, 
                      std::vector<bool>& visited) {
                          
        visited[start] = true;
        if (prev[start].size() == 0) {
            return fun[start];
        }
        
        long long minFun = fun[start];
        long long sumFun = fun[start];
        for (int p : prev[start]) {
            long long prevFun = trigger(p, prev, fun, visited);
            minFun = (minFun < prevFun) ? minFun : prevFun;
            sumFun += prevFun;
        }
        
        return sumFun - minFun;
    }
}

int main(int arg, char** argv) {
    int casesCount = 0;
    std::cin >> casesCount;
    
    int casesIndex = 1;
    while (casesIndex <= casesCount) {
        printf("Case #%d: ", casesIndex);
        int modulesCount;
        std::cin >> modulesCount;
        
        std::vector<long long> fun{ 0/*abyss*/ };
        ::readBatchData<long long>(fun, modulesCount);
        std::vector<int> point{ 0/*abyss*/ };
        ::readBatchData<int>(point, modulesCount);
        
        std::vector<bool> visited(point.size(), false);
        std::vector<std::vector<int>> prev(point.size());
        ::findPrevModules(prev, point);
        
        long long maxFun = ::trigger(0, prev, fun, visited);
        
        for (int i = 1; i < visited.size(); ++i) {
            if (!visited[i]) {
                maxFun += ::trigger(i, prev, fun, visited);
            }
        }
        
        std::cout << maxFun << std::endl;
        ++casesIndex;
    }
    
    return 0;
}
```

2. 
```c++
#include <stdio.h>

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace {
    template <typename T>
    void inline readBatchData(std::vector<T>& in, const int size) {
        T tmp;
        for (int i = 0; i < size; ++i) {
            std::cin >> tmp;
            in.push_back(tmp);
        }
    }
    
    void inline findPrevModules(std::vector<std::vector<int>>& prev, 
                                const std::vector<int>& point) {
        for (int i = 1; i < point.size(); ++i) {
            prev[point[i]].push_back(i);
        }
    }
    
    long long trigger(const int current,
                      long long& valueOfPath,
                      const std::vector<std::vector<int>>& prev, 
                      const std::vector<long long>& fun) {
        if (prev[current].size() == 0) {
            valueOfPath = fun[current];
            return fun[current];
        }
        
        long long sumFun = 0;
        long long currPathFun = LLONG_MAX;
        for (int p : prev[current]) {
            long long prevPathFun;
            sumFun += trigger(p, prevPathFun, prev, fun);
            currPathFun = (currPathFun < prevPathFun) ? currPathFun : prevPathFun;
        }
        
        if (currPathFun < fun[current]) {
            sumFun += fun[current] - currPathFun;
            currPathFun = fun[current];
        }
        valueOfPath = currPathFun;
        
        return sumFun;
    }
}

int main(int arg, char** argv) {
    int casesCount = 0;
    std::cin >> casesCount;
    
    int casesIndex = 1;
    while (casesIndex <= casesCount) {
        printf("Case #%d: ", casesIndex);
        
        int modulesCount;
        std::cin >> modulesCount;
        
        std::vector<long long> fun{ 0/*abyss*/ };
        ::readBatchData<long long>(fun, modulesCount);
        std::vector<int> point{ -1/*abyss*/ };
        ::readBatchData<int>(point, modulesCount);
        
        std::vector<std::vector<int>> prev(point.size(), std::vector<int>{});
        ::findPrevModules(prev, point);
        
        long long valueOfPath;
        long long maxFun = ::trigger(0, valueOfPath, prev, fun);
        
        std::cout << maxFun << std::endl;
        ++casesIndex;
    }
    
    return 0;
}
```

## References ##
- [Google Codejam 2022 - "Chain Reactions"](https://www.youtube.com/watch?v=ZIPwxivGA6k)