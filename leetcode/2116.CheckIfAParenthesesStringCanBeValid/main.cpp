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
    bool canBeValid(string s, string locked) {
        stack<int> unlocked;
        stack<int> open;

        if (s.size() % 2 == 1) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (locked[i] == '0') {
                unlocked.push(i);
            } else {
                if (c == '(') {
                    open.push(i);
                } else { // )
                    if (!open.empty()) {
                        open.pop();
                    } else if (!unlocked.empty()) {
                        unlocked.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        while (!open.empty() && !unlocked.empty() && unlocked.top() > open.top()) {
            unlocked.pop();
            open.pop();
        }
        if (!open.empty()) {
            return false;
        }

        return true;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "))()))";
    string locked = "010100";
    cout << sol.canBeValid(s, locked) << "\n"; // 1

    s = ")(";
    locked = "00";
    cout << sol.canBeValid(s, locked) << "\n"; // 1

    s = "((";
    locked = "00";
    cout << sol.canBeValid(s, locked) << "\n"; // 1

    s = "((()(()()))()((()()))))()((()(()";
    locked = "10111100100101001110100010001001";
    cout << sol.canBeValid(s, locked) << "\n"; // 1
    return 0;
}

