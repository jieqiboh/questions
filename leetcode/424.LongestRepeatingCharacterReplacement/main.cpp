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
    int characterReplacement(string s, int k) {
        // Main idea:
        // Want all chars to match most freq char in a window
        // Find the max window where windowsize - maxfreq <= k

        int res = 0;
        int l = 0;
        map<char, int> count;
        for (int r = 0; r < s.size(); r++) {
            int window_size = r - l + 1;

            count[s[r]] += 1;

            int max_freq = 0;
            for (auto& x : count) {
                max_freq = max(max_freq, x.second);
            }

            if (window_size - max_freq <= k) {
                res = max(res, window_size);
                continue;
            } else {
                count[s[l]] -= 1;
                l++;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << sol.characterReplacement(s, k) << "\n";

    return 0;
}

