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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = 1000;
        for (const string& s : strs) {
            minLen = min(minLen, static_cast<int>(s.length()));
        }

        int res = 0;
        for (int i = 0; i < minLen; i++) {
            bool match = true;
            const char c = strs[0][i];
            for (auto & str : strs) {
                if (str[i] != c) {
                    match = false;
                    break;
                }
            }
            if (!match) break;
            res++;
        }
        return strs[0].substr(0, res);
    }
};

int main() {
    fast();
    Solution sol;
    vector<string> strs = {"bat","bag","bank","band"};
    cout << sol.longestCommonPrefix(strs) << "\n";

    strs = {"dance","dag","danger","damage"};
    cout << sol.longestCommonPrefix(strs) << "\n";

    strs = {"neet", "feet"};
    cout << sol.longestCommonPrefix(strs) << "\n";
    return 0;
}

