#include <iostream>
#include <algorithm>

int main()
{
    int numOfTests;
    std::cin >> numOfTests;
    
    int a, b, c, x, y;
    while (numOfTests--) {
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        std::cin >> x;
        std::cin >> y;
        
        int dog_res = std::max(0, x - a);
        int cat_res = std::max(0, y - b);
        
        if (dog_res + cat_res <= c) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}
