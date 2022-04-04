#include <stdio.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace {
    void inline reset(std::vector<int>& in, const int value) {
        for (int& i : in) i = value;
    }
    
    bool clacColor(std::vector<int>& colors,
                   std::vector<int>& ink,
                   const int totalInk) {
        int resInk = totalInk;
        for (int i = 0; i < colors.size(); ++i) {
            if (ink[i] < resInk) {
                resInk -= ink[i];
                colors[i] = ink[i];
            } else { // done
                colors[i] = resInk;
                resInk -= ink[i];
                return true;
            }
        }
        
        return (resInk <= 0);
    }
}

int main(int arg, char** argv) {
    const int totalInk = 1000000;
    
    int casesCount = 0;
    const int sizeOfBatchData = 3;
    std::cin >> casesCount;
    
    int casesIndex = 1;
    int c, m, y, k;
    std::vector<int> minInk(4, INT_MAX);
    std::vector<int> colors(4, 0);
    for (; casesIndex <= casesCount; ++casesIndex) {
        printf("Case #%d: ", casesIndex);
        
        reset(minInk, INT_MAX);
        for (int i = 0; i < sizeOfBatchData; ++i) {
            scanf("%d %d %d %d", &c, &m, &y, &k);
            minInk[0] = std::min(minInk[0], c);
            minInk[1] = std::min(minInk[1], m);
            minInk[2] = std::min(minInk[2], y);
            minInk[3] = std::min(minInk[3], k);
        }
        
        reset(colors, 0);
        bool result = clacColor(colors, minInk, totalInk);
        if (result) {
            std::cout << colors[0] << " " 
                      << colors[1] << " "
                      << colors[2] << " "
                      << colors[3];
        } else {
            std::cout << "IMPOSSIBLE";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
