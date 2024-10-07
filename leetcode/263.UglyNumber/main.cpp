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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool isUgly(int n) {
        if (n == 1) {
            return true;
        } else {
            bool b1 = false;
            bool b2 = false;
            bool b3 = false;

            if (n % 2 == 0) {
                b1 = isUgly(n / 2);
            }
            if (n % 3 == 0) {
                b2 = isUgly(n / 3);
            }
            if (n % 5 == 0) {
                b3 = isUgly(n / 5);
            }
            return b1 || b2 || b3;
        }
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.isUgly(6) << "\n"; // 1
    cout << sol.isUgly(1) << "\n"; // 1
    cout << sol.isUgly(14) << "\n"; // 0

    return 0;
}

