# [CountNonDivisible](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/)


# Total Score 66
```c++
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> solution(vector<int>& A) {
    map<int, int> showTimes;
    for (int i = 0; i < A.size(); ++i) {
        ++showTimes[A[i]];
    }

    vector<int> ans;
    map<int, int>::iterator it;
    int count;
    for (int i = 0; i < A.size(); ++i) {
        it = showTimes.begin();
        count = 0;
        int limit = static_cast<int>(sqrt(A[i]));
        while (it != showTimes.end()) {
            if (A[i] % it->first != 0)
                count += it->second;
            ++it;
        }
        ans.push_back(count);
    }

    return ans;
}
```

### Comment
找非因數很麻煩，改找因數再扣掉的

## Total Score 22
```c++
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> solution(vector<int>& A) {
    map<int, int> showTimes;
    for (int i = 0; i < A.size(); ++i) {
        ++showTimes[A[i]];
    }

    vector<int> ans;
    map<int, int> buffer;
    map<int, int>::iterator it;
    int count;
    for (int i = 0; i < A.size(); ++i) {
        it = showTimes.begin();
        count = 0;
        
        if (buffer.find(A[i]) != buffer.end()) {
            ans.push_back(buffer[A[i]]);
            continue;
        }

        int limit = static_cast<int>(sqrt(A[i]));
        while (it->first <= limit && it != showTimes.end()) {
            if (A[i] % it->first == 0) {
                count += it->second;
                int another_factor = A[i] / it->first;
                if (another_factor != it->first 
                    && showTimes.find(another_factor) != showTimes.end()) {

                    count += showTimes[another_factor];
                }
            }
            ++it;
        }
        ans.push_back(A.size() - count);
        buffer[A[i]] = A.size() - count;
    }

    return ans;
}
```


### Comment
只找現有的元素無法考慮到所有可能性，
例如 [3, 3, 6] 沒有 1 ， 3 就無法被找到(小於 sqrt(3))。

## Total Score 100
```c++
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

namespace {
    inline int exist(map<int, int>& m, const int target) {
        if (m.find(target) != m.end()) {
            return m[target];
        }
        else {
            return 0;
        }
    }
}

vector<int> solution(vector<int>& A) {
    map<int, int> showTimes;
    for (int i = 0; i < A.size(); ++i) {
        ++showTimes[A[i]];
    }

    vector<int> ans;
    map<int, int> buffer;
    int count;
    int num;
    for (int i = 0; i < A.size(); ++i) {
        if (buffer.find(A[i]) != buffer.end()) {
            ans.push_back(buffer[A[i]]);
            continue;
        }
        
        count = 0;
        num = 1;
        int limit = static_cast<int>(sqrt(A[i]));
        for (; num <= limit; ++num) {
            if (A[i] % num == 0) {
                count += exist(showTimes, num);
                int other_factor = A[i] / num;
                if (other_factor != num) {
                    count += exist(showTimes, other_factor);
                }
            }
        }
        ans.push_back(A.size() - count);
        buffer[A[i]] = A.size() - count;
    }

    return ans;
}
```