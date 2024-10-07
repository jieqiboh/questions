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
    int longestSubstring(string s, int k) {
        // divide and conquer
        return helper(s, k, 0, s.size() - 1);

    }
    int helper(string s, int k, int i, int j) {
        // returns the longestSubstring
        // s and k are original
        // [i, j] denote range to explore
        if (i > j) return 0;
        map<char, int> freq; // maps char to their frequency in the arr
        for (int l = i; l <= j; l++) {
            freq[s[l]]++;
        }

        int leftSize = 0;
        int rightSize = 0;
        for (int l = i; l <= j; l++) {
            if (freq[s[l]] < k) {
                leftSize = helper(s, k, i, l-1);
                rightSize = helper(s, k, l+1, j);
                return max(leftSize, rightSize);
            }
        }
        return j - i + 1;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "ababbc";
    int k = 2;
    cout << sol.longestSubstring(s, k) << "\n"; // 5

    s = "ababacb";
    k = 3;
    cout << sol.longestSubstring(s, k) << "\n"; // 0

//    s = "bat";
//    sort(s.begin(), s.end());
//    cout << s << "\n";
    return 0;
}

