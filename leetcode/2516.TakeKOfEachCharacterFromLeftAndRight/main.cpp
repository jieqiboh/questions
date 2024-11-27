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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int l = 0;
        // [l, r] is the window of chars to exclude
        unordered_map<int,int> freq;
        freq['a'] = k;
        freq['b'] = k;
        freq['c'] = k;
        for (char c : s) { // initially include all chars
            freq[c]--;
        }
        if (freq['a'] > 0 || freq['b'] > 0 || freq['c'] > 0) return -1;

        int res = INT32_MAX;
        for(int r = 0; r < s.size(); r++) {
            // try excluding s[r]
            freq[s[r]]++;
            if (freq[s[r]] > 0) { // cannot exclude
                while (freq[s[r]] > 0) {
                    freq[s[l]]--;
                    l++;
                }
            }
            res = min(res, (int)s.size() - (r - l + 1));
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "aabaaaacaabc";
    int k = 2;
    cout << sol.takeCharacters(s, k) << "\n"; // 8

    s = "a";
    k = 1;
    cout << sol.takeCharacters(s, k) << "\n"; // -1

    s = "aaabaaaacabababcca";
    k = 3;
    cout << sol.takeCharacters(s, k) << "\n"; // 10

    s = "caccbbba";
    k = 1;
    cout << sol.takeCharacters(s, k) << "\n"; // 3

    s = "aabbccca";
    k = 2;
    cout << sol.takeCharacters(s, k) << "\n"; // 6
    return 0;
}

