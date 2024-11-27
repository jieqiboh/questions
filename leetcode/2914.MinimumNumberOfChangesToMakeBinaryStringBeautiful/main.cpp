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
    int minChanges(string s) {
        int res = 0;
        int cur = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == cur) {
                cnt++;
            } else {
                if (cnt % 2 == 0) { // prev substr isEven
                    cur = s[i];
                    cnt = 1;
                } else {
                    res++; // change this char to be equal to cur
                    cnt++;
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "000111";
    cout << sol.minChanges(s) << "\n"; // 1

    s = "0001";
    cout << sol.minChanges(s) << "\n"; // 1

    s = "0000";
    cout << sol.minChanges(s) << "\n"; // 0

    s = "10";
    cout << sol.minChanges(s) << "\n"; // 1

    s = "1001";
    cout << sol.minChanges(s) << "\n"; // 2
    return 0;
}

