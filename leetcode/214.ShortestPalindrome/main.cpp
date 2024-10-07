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
    string shortestPalindrome(string s) {
        int length = s.length();
        if (length == 0) {
            return s;
        }
        // find longest palindromic prefix
        int l = 0;
        for (int r = s.size() - 1; r >= 0; r--) {
            if (s[r] == s[l]) l++;
        }
        string rev = s.substr(l);
        reverse(rev.begin(), rev.end());
        return rev + shortestPalindrome(s.substr(0,l)) + s.substr(l);
    }
};

int main() {
    fast();
    Solution sol;
    string s = "aacecaaa";
    cout << sol.shortestPalindrome(s) << "\n";

    return 0;
}

