# [GenomicRangeQuery](https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/)

## Total Score 100
```c++
#include <array>
#include <cstddef>
#include <vector>
#include <string>

using namespace std;

namespace {
    void inline fill(
        vector<array<int, 4>>& show,
        const size_t impFactIndex,
        const size_t i) {

        for (size_t ii = i - 1; ii >= 0; --ii) {
            if (show[ii][impFactIndex] == -1) {
                show[ii][impFactIndex] = i;
            }
            else {
                break;
            }
        }
    }

    void assignFirstShow(const string& s, 
        vector<array<int, 4>>& show) {
        
        for (size_t i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'A':
                    show[i][0] = i;
                    fill(show, 0, i);
                    break;
                case 'C':
                    show[i][1] = i;
                    fill(show, 1, i);
                    break;
                case 'G':
                    show[i][2] = i;
                    fill(show, 2, i);
                    break;
                case 'T':
                    show[i][3] = i;
                    fill(show, 3, i);
                    break;
            }
        }
    }
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    array<int, 4> tmp{-1, -1, -1, -1};
    vector<array<int, 4>> firstShow(S.size(), tmp);
    assignFirstShow(S, firstShow);

    vector<int> ans;
    for (size_t i = 0; i < P.size(); ++i) {
        int start = P[i];
        int end = Q[i];
        // A C G T
        for (size_t impfact = 1; impfact <= 4; ++impfact) {
            if (firstShow[start][impfact - 1] <= end && firstShow[start][impfact - 1] != -1) {
                ans.push_back(impfact);
                break;
            }
        }
    }

    return ans;
}
```