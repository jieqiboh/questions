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
    string longestPalindrome(string s) {
        if (s.length() == 1) return s; // edge case
        int res_l = 0; int res_r = 0;

        int max_len = 1;
        for (int i = 0; i < s.length(); i++) { // odd length substrings
            int cur_max = 1;
            int l = i; int r = i;
            while (l >= 0 && r <= s.length() - 1) {
                if (s[l] == s[r]) {
                    cur_max = r - l + 1;
                    max_len = max(max_len, cur_max);
                    if (cur_max == max_len) {
                        res_l = l;
                    }
                    l--; r++;
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < s.length(); i++) { // even length substrings
            int cur_max = 2;
            int l = i; int r = i+1;
            while (l >= 0 && r <= s.length() - 1) {
                if (s[l] == s[r]) {
                    cur_max = r - l + 1;
                    max_len = max(max_len, cur_max);
                    if (cur_max == max_len) {
                        res_l = l;
                    }
                    l--; r++;
                } else {
                    break;
                }
            }
        }
        return s.substr(res_l, max_len);
    }
};

int main() {
    fast();

    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << "\n";

    s = "cbbd";
    cout << sol.longestPalindrome(s) << "\n";

    return 0;
}

