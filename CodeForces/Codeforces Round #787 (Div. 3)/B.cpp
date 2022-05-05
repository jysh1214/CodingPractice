#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

namespace {
    int clac(std::vector<int>& vec) {
        if (vec.size() == 1) return 0;
        int count = 0;
        for (int i = vec.size() - 2; i >= 0; --i) {
            while (vec[i] >= vec[i + 1]) {
                vec[i] = vec[i] / 2;
                ++count;
            }
            
            if (i > 0 && vec[i] == 0)
                return -1;
        }
        
        return count;
    }
}

int main() {
    int numOfTests;
    std::cin >> numOfTests;
    
    int numCount, elem;
    while (numOfTests--) {
        std::cin >> numCount;
        std::vector<int> vec;
        while (numCount--) {
            std::cin >> elem;
            vec.push_back(elem);
        }
        int count = clac(vec);
        std::cout << count << std::endl;
    }
    
    return 0;
}
