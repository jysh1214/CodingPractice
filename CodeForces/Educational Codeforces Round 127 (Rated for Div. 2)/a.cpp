#include <iostream>

namespace {
    bool check(const std::string& input) {
        if (input.size() == 1) return false;
        if (input[0] != input[1]) return false;
        if (input.back() != input[input.size() - 2]) return false;
        
        for (int i = 1; i < input.size() - 1; ++i) {
            if (input[i] != input[i - 1] && input[i] != input[i + 1])
                return false;
        }
        
        return true;
    }
}

int main(int arg, char** argv) {
    int casesCount;
    std::cin >> casesCount;
    
    std::string input;
    while (casesCount--) {
        std::cin >> input;
        if (check(input)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
