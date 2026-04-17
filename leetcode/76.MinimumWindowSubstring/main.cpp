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
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int have = 0; // the amt of chars we've fulfilled so far
        int required = 0; // amt of chars we still need to fulfil
        int minLen = INT_MAX, minLeft = 0;
        string res = s;
        if (t.size() > s.size()) return "";

        unordered_map<char,int> freq; // tracks the amt of a certain char we need
        for (char c : t) {
            freq[c]++;
        }
        required = freq.size();

        // expand right to find minimally sufficient substr, then shrink left to optimize
        bool foundOne = false;
        while (right < s.size()) {
            while (have != required && right < s.size()) {
                // traverse right until we fulfil this
                char cur = s[right];
                if (freq.find(cur) != freq.end()) { // part of the chars that exist in t
                    freq[cur]--;
                    if (freq[cur] == 0) have++;
                }
                right++;
            }

            // traverse left until we fulfil this
            while (have == required && left <= right) {
                // update the res string if we can
                if (right - left < minLen) {
                    minLen = right - left;
                    minLeft = left;
                }

                char cur = s[left];
                left++;
                if (freq.find(cur) != freq.end()) { // part of the chars that exist in t
                    freq[cur]++;
                    if (freq[cur] > 0) {
                        have--;
                        break; // exit the while loop, found char
                    }
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    fast();
    Solution sol;
    string s = "a";
    string t = "a";
    cout << sol.minWindow(s, t) << "\n";

    return 0;
}

