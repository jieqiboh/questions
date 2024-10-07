#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>
#include <numeric>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1; i < sqrt(n); i++) { // divisors < sqrt(n)
            if (n % i == 0) {
                k--;
                if (k == 0) return i;
            }
        }
        for (int i = sqrt(n); i >= 1; i--) { // divisors >= sqrt(n)
            if (n % (n / i) == 0) {
                k--;
                if (k == 0) return n/i;
            }
        }
        return -1;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.kthFactor(12, 3) << "\n"; // 3

    cout << sol.kthFactor(7, 2) << "\n"; // 7

    cout << sol.kthFactor(4, 4) << "\n"; // -1

    cout << sol.kthFactor(9, 2) << "\n"; // 3
    return 0;
}

