#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

namespace {
    std::vector<char> removeDuplicated(std::vector<char>& input) {
        std::vector<char> ans;
        int p = -1;
        for (char i : input) {
            if (ans.empty() || ans[p] != i) {
                ans.push_back(i);
                ++p;
            }
        }
        
        return ans;
    }
    
    bool check(std::vector<char>& input) {
        std::vector<char> filter = removeDuplicated(input);
        if (filter.empty()) {
            return false;  
        } else if (filter.size() == 1) {
			return filter[0] == 'W';
		} else if (filter.size() == 2) {
			if (filter[0] == 'W' || filter[1] == 'W') {
			    return false;
			}
			return true;
		}
		
		if (filter.front() != 'W' && filter[1] == 'W') return false;
		if (filter.back() != 'W' && filter[filter.size() - 2] == 'W') return false;
        
        for (int i = 1; i < filter.size() - 1; ++i) {
            if (filter[i - 1] == 'W' && filter[i + 1] == 'W')
                return false;
        }
        
        return true;
    }
}

int main(int arg, char** argv) {
    int casesCount;
    std::cin >> casesCount;
    
    int len;
    char elem;
    while (casesCount--) {
        std::cin >> len;
        
        std::vector<char> input;
        while (len--) {
            std::cin >> elem;
            input.push_back(elem);
        }
        
        if (check(input)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
