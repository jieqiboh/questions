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
    int lengthOfLongestSubstring(string s) {
        set<char> seen;
        int max_len = 0;

        if (s.empty()) return 0;

        // at the start of every loop, seen contains all the chars in [l,r]
        // at the start of every loop, s[l,r] is a valid substring
        int l = 0; int r = 0;
        seen.insert(s[r]);

        while (l <= r && r < s.size()) {
            max_len = max(max_len, r - l + 1);
            r++; // shift r to the right
            if (r < s.size()) { // within bounds
                if (seen.find(s[r]) == seen.end()) {
                    seen.insert(s[r]);
                } else {
                    while (l <= r && s[l] != s[r]) {
                        seen.erase(s[l]);
                        l++;
                    }
                    l++;

                }
            }

        }

        return max_len;
    }
};

int main() {
    fast();

    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << "\n"; // abc - 3

    s = "bbbbb";
    cout << sol.lengthOfLongestSubstring(s) << "\n"; // b - 1

    s = "";
    cout << sol.lengthOfLongestSubstring(s) << "\n"; // 0

    s = "dvdf";
    cout << sol.lengthOfLongestSubstring(s) << "\n"; // vdf - 3

    return 0;
}

