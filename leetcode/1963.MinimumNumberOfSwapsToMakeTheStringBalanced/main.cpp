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
    int minSwaps(string s) {
        if (s == "") return 0;
        int swps = 0;
        int open = 0;
        int close = 0;

        for (char c : s) {
            if (c == '[') {
                open++;
            } else {
                close++;
                if (close > open) {
                    swps++;
                    close--;
                }
            }
        }
        return swps%2 + swps/2;
    }
};

int main() {
    fast();

    Solution sol;
    string s = "]]][[[";
    cout << sol.minSwaps(s) << "\n"; // 2

    s = "[]";
    cout << sol.minSwaps(s) << "\n"; // 0

    s = "][";
    cout << sol.minSwaps(s) << "\n"; // 1

    s = "][][][";
    cout << sol.minSwaps(s) << "\n"; // 1

    s = "[[][]]";
    cout << sol.minSwaps(s) << "\n"; // 0

    s = "]]]][[[[";
    cout << sol.minSwaps(s) << "\n"; // 2

    s = "]]]]][[[[[";
    cout << sol.minSwaps(s) << "\n"; // 3
    return 0;
}

