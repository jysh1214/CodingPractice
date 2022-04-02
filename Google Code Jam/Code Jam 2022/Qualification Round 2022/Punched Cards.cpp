#include <stdio.h>

#include <iostream>
#include <string>

namespace {
    bool inline isEven(const int n) {
        return (n % 2 == 0);
    }
    
    void printCard(const int _row, const int _col) {
        int row = _row * 2 + 1;
        int col = _col * 2 + 1;
        
        for (int j = 0; j < row; ++j) {
            for (int i = 0; i < col; ++i) {
                if (j < 2 && i < 2) {
                    std::cout << ".";
                } else if (isEven(j) && isEven(i)) {
                    std::cout << "+";
                } else if (isEven(j) && !isEven(i)) {
                    std::cout << "-";
                } else if (!isEven(j) && isEven(i)) {
                    std::cout << "|";
                } else {
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
    }
}

int main(int arg, char** argv) {
    int casesCount = 0;
    std::cin >> casesCount;
    
    int casesIndex = 1;
    int row, col;
    while (casesIndex <= casesCount) {
        scanf("%d %d", &row, &col);
        printf("Case #%d:\n", casesIndex);
        ::printCard(row, col);
        ++casesIndex;
    }
    
    return 0;
}
