# [TricoloredTowers](https://app.codility.com/programmers/custom_challenge/year_of_the_tiger_2022/)

```c++
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

namespace {
    bool isConnect(const std::string& a, const std::string& b) {
        bool firstDiff = false;
        bool thirdtDiff = false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (i == 0) firstDiff = true;
                if (i == 2) thirdtDiff = true;
            }
        }

        return (firstDiff && thirdtDiff) ? false : true;
    }

    int patternCount(std::vector<std::string>& candidates, 
                     const std::string& pattern) {
        
        int count = 0;
        for (const std::string& c : candidates) {
            if (isConnect(c, pattern)) ++count;
        }

        return count;
    }
}

int solution(std::vector<std::string> &T) {
    std::unordered_map<std::string, std::vector<std::string>> count;
    for (std::string t : T) {
        std::string sorted = t;
        std::sort(sorted.begin(), sorted.end());
        count[sorted].push_back(t);
    }

    int maxCount = 1;
    for (auto it = count.begin(); it != count.end(); ++it) {
        std::string pattern = it->first;
        maxCount = std::max(maxCount, patternCount(it->second, pattern));
        while (std::next_permutation(pattern.begin(), pattern.end())) {
            maxCount = std::max(maxCount, patternCount(it->second, pattern));
        }
    }

    return maxCount;
}
```