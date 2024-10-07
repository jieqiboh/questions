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
    int rangeBitwiseAnd(int left, int right) {
        // find the longest common prefix of the binary rep of left and right
        // O(1)
        int tmpl = left;
        int tmpr = right;
        for (int i = 0; i < 32; i++) {
            if (tmpl == tmpr) {
                return tmpl << i;
            };
            tmpl >>= 1;
            tmpr >>= 1;
        }
        return 0;
    }
};

int main() {
    fast();
    Solution sol;
    int left = 5;
    int right = 7;
    cout << sol.rangeBitwiseAnd(left, right) << "\n"; // 4

    left = 0;
    right = 0;
    cout << sol.rangeBitwiseAnd(left, right) << "\n"; // 0

    left = 1;
    right = INT32_MAX;
    cout << sol.rangeBitwiseAnd(left, right) << "\n"; // 0
    return 0;
}

