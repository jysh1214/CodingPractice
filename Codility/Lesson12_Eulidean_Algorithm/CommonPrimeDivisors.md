# [CommonPrimeDivisors](https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/)

## Total Score 100
```c++
#include <vector>

using namespace std;

namespace {
    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    bool check(int a, int b) {
        int g = gcd(a, b);
        while (g != 1) {
            a /= g;
            g = gcd(b, a);
        }

        return (a == 1) ? true : false;
    }
}

int solution(vector<int>& A, vector<int>& B) {
    int count = 0;
    for (int i = 0; i < A.size(); ++i) {
        int a = A[i];
        int b = B[i];
        if (a == b) {
            ++count;
            continue;
        }
        int g = gcd(a, b);
        if (check(a, g) && check(b, g))
            ++count;
    }

    return count;
}
```