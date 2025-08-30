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
    int longestSubsequence(string s, int k) {
        // include all 0s
        // then count from right to left and include 1s if they dont cause exceed
        int res = 0;
        long long cur = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                res++;
            } else if (cur + pow(2, s.size() - 1 - i) <= k) {
                cur += pow((long long)2, s.size() - 1 - i);
                res++;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "1001010";
    int k = 5;
    cout << sol.longestSubsequence(s, k) << "\n"; // 5

    s = "00101001";
    k = 1;
    cout << sol.longestSubsequence(s, k) << "\n"; // 6

    return 0;
}

