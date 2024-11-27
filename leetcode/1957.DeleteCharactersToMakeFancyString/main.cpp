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
    string makeFancyString(string s) {
        int cnt = 1;
        char cur = s[0];
        string resStr = "";
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == cur) {
                cnt++;
            } else {
                resStr += string(min(2, cnt), cur);
                cnt = 1;
                cur = s[i];
            }
        }
        resStr += string(min(2, cnt), cur);
        return resStr;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "leeeetcode";
    cout << sol.makeFancyString(s) << "\n"; // leetcode

    return 0;
}

