#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
    void solution(std::vector<int>& input) {
        std::unordered_map<int, int> m;
        for (int n : input) {
            ++m[n];
        }
        
        auto it = m.begin();
        for (; it != m.end(); ++it) {
            if (it->second >= 3) {
                std::cout << it->first << std::endl;
                return;
            }
        }
        
        std::cout << -1 << std::endl;
    }
}

int main(int arg, char** argv) {
    int casesCount;
    std::cin >> casesCount;
    
    int len;
    int elem;
    while (casesCount--) {
        std::cin >> len;
        
        std::vector<int> input;
        while (len--) {
            std::cin >> elem;
            input.push_back(elem);
        }
        
        solution(input);
    }

    return 0;
}
