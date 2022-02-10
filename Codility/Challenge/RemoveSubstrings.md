# [RemoveSubstrings](https://app.codility.com/programmers/challenges/pairacoder_2022/)

## Total Score 100
```c++
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string &S) {
    // 被移除後的最小值
    unordered_map<int, int> charmin;
    vector<int> dp(S.size(), 0);
    dp[0] = 1;
    charmin[S[0]] = 0;
    for (int i = 1; i < S.size(); ++i) {
        if (charmin.find(S[i]) != charmin.end()) {
            dp[i] = min(dp[i - 1] + 1, charmin[S[i]]);
            charmin[S[i]] = min(charmin[S[i]], dp[i - 1]);
        }
        else {
            dp[i] = dp[i - 1] + 1;
            charmin[S[i]] = dp[i - 1];
        }
    }

    return dp.back();
}
```