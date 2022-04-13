#include <stdio.h>
#include <iostream>
#include <string>

namespace {
    std::string nextDouble(std::string& input) {
        std::string result = "";
        int count = 0;
        for (int i = 0; i < input.size(); ++i) {
            result += input[i];
            if (i < input.size() - 1 && input[i] < input[i + 1]) {
                result += input[i];
                while (count--) result += input[i];
                count = 0;
            } else if (i < input.size() - 1 && input[i] == input[i + 1]) {
                ++count;
            } else {
                count = 0;
            }
        }
        
        return result;
    }
}

int main(int arg, char** argv) {
    int casesCount = 0;
    std::cin >> casesCount;
    
    int casesIndex = 1;
    for (; casesIndex <= casesCount; ++casesIndex) {
        printf("Case #%d: ", casesIndex);
        
        std::string intput;
        std::cin >> intput;
        std::string result = ::nextDouble(intput);
        std::cout << result << "\n";
    }

    return 0;
}