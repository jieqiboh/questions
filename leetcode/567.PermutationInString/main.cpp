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
    bool checkInclusion(string s1, string s2) {
        // check if s2 contains a substring with the same char freq as s1
        unordered_map<char, int> s1_counts;
        for (char c : s1) {
            s1_counts[c]++;
        }
        if (s1.length() > s2.length()) return false;
        unordered_map<char, int> s2_counts;
        int l = 0;

        for (int i = 0; i < s1.length(); i++) { // init s2_counts
            s2_counts[s2[i]]++;
        }

        for (int r = s1.size() - 1; r < s2.size(); r++) {
            if (match(s1_counts, s2_counts)) {
                return true;
            } else {
                if (r + 1 < s2.size()) s2_counts[s2[r + 1]]++;
                s2_counts[s2[l]]--;
                l++;
            }
        }
        return false;
    }
    bool match(unordered_map<char, int> s1_c, unordered_map<char, int> s2_c) {
        // checks if the 2 hashmaps match
        for (pair<char, int> p : s1_c) {
            if (s2_c[p.first] != p.second) return false;
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << sol.checkInclusion(s1, s2) << "\n"; // 1

    s1 = "ab";
    s2 = "eidboaooo";
    cout << sol.checkInclusion(s1, s2) << "\n"; // 0

    s1 = "ab";
    s2 = "eidboaoooba";
    cout << sol.checkInclusion(s1, s2) << "\n"; // 1
    return 0;
}

