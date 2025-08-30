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
    bool canConstruct(string s, int k) {
        unordered_map<char,int> counts;
        if (s.size() < k) {
            return false; // no way to form enough palindromes
        }

        for (char c : s) {
            counts[c]++;
        }

        int oddCount = 0;
        for (pair<int,int> p : counts) {
            if (p.second % 2 != 0) {
                oddCount++;
            }
        }

        return oddCount <= k;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "annabelle";
    int k = 2;
    cout << sol.canConstruct(s, k) << "\n"; // 1

    s = "leetcode";
    k = 3;
    cout << sol.canConstruct(s, k) << "\n"; // 0
    return 0;
}

