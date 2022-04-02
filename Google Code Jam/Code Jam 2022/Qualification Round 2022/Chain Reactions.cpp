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
