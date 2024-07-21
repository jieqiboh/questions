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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = INT32_MAX;
        for (string s: strs) {
            min_len = min(min_len, (int) s.size());
        }

        string longest = "";
        bool all_same = true;

        for (int i = 0; i < min_len; i++) {
            char c = strs[0][i];

            for (string s: strs) {
                if (s[i] != c) {
                    all_same = false;
                    break;
                }
            }

            if (all_same) {
                longest += c;
            } else {
                break;
            }
        }
        return longest;
    }
};

int main() {
    fast();

    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(strs);

    strs = {"dog","racecar","car"};
    cout << sol.longestCommonPrefix(strs);

    return 0;
}

