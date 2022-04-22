#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

namespace {
    bool check(std::vector<int>& input) {
        for (int i = 0; i < input.size() - 1; ++i) {
            if ((input[i + 1] - input[i]) % 2 == 1) return false;
        }
        return true;
    }
    
    void solution(std::vector<int>& input) {
        std::vector<int> odd;
        std::vector<int> even;
        for (int i = 0; i < input.size(); ++i) {
            if (i % 2 == 0) odd.push_back(input[i]);
            else even.push_back(input[i]);
        }
        
        std::sort(odd.begin(), odd.end());
        std::sort(even.begin(), even.end());
        
        if (!check(odd)) {
            std::cout << "NO\n";
            return;
        }
        if (!check(even)) {
            std::cout << "NO\n";
            return;
        }
        
        std::cout << "YES\n";
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
