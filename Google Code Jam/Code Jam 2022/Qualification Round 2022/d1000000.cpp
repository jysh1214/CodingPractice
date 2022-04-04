#include <stdio.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace {
    int calcMaxStraight(std::vector<int>& dices) {
        std::sort(dices.begin(), dices.end());
        int maxStrainght = 0;
        for (int i = 0; i < dices.size(); ++i) {
            if (maxStrainght + 1 <= dices[i])
                ++maxStrainght;
            if (maxStrainght > dices.back())
                break;
        }
        
        return maxStrainght;
    }
}

int main(int arg, char** argv) {
    int casesCount = 0;
    std::cin >> casesCount;
    
    int casesIndex = 1;
    while (casesIndex <= casesCount) {
        printf("Case #%d: ", casesIndex);
        
        int diceCount;
        std::cin >> diceCount;
        
        std::vector<int> dices;
        while (diceCount--) {
            int dice_val;
            std::cin >> dice_val;
            dices.push_back(dice_val);
        }
        
        int maxStraight = ::calcMaxStraight(dices); 
        std::cout << maxStraight << std::endl;
        ++casesIndex;
    }
    
    return 0;
}
