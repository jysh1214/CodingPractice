#include <iostream>

int main(int arg, char** argv) {
    int casesCount;
    std::cin >> casesCount;
    
    int rating;
    while (casesCount--) {
        std::cin >> rating;
        if (rating >= 1900) std::cout << "Division " << 1 << "\n";
        else if (rating >= 1600 && rating <= 1899) std::cout << "Division " << 2 << "\n";
        else if (rating >= 1400 && rating <= 1599) std::cout << "Division " << 3 << "\n";
        else if (rating <= 1399) std::cout << "Division " << 4 << "\n";
    }

    return 0;
}
