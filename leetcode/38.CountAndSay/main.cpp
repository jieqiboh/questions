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
    string countAndSay(int n) {
        string res = "1";
        for (int i = 0; i < n - 1; i++) {
            res = rle(res);
        }
        return res;
    }

    string rle(string s) {
        string res = "";
        char cur = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (cur == s[i]) {
                cnt++;
            } else {
                res += to_string(cnt);
                res += cur;
                cur = s[i];
                cnt = 1;
            }
        }
        res += to_string(cnt);
        res += cur;
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.countAndSay(4) << "\n";

    return 0;
}

