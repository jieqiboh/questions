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
    bool canChange(string start, string target) {
        unordered_map<char,int> startcnt;
        unordered_map<char,int> targcnt;
        for (int i = 0; i < start.size(); i++) {
            startcnt[start[i]]++;
            targcnt[target[i]]++;
        }
        if (startcnt['R'] != targcnt['R'] || startcnt['L'] != targcnt['L']) return false;

        int j = start.size() - 1;

        for (int i = target.size() - 1; i >= 0; i--) {
            if (target[i] == '_') continue;

            if (target[i] == 'R') {
                while (j >= 0 && start[j] != 'R') {
                    j--;
                }
                if (j < 0 || j > i) return false; // cannot move R to required pos
                j--;
            } else { // i == L
                while (j >= 0 && start[j] != 'L') {
                    j--;
                }
                if (j < 0 || j < i) return false; // cannot move L to required pos
                j--;
            }
        }

        return true;
    }
};

int main() {
    fast();
    Solution sol;
    string start = "_L__R__R_";
    string target = "L______RR";
    cout << sol.canChange(start, target) << "\n"; // 1

    start = "R_L_";
    target = "__LR";
    cout << sol.canChange(start, target) << "\n"; // 0

    start = "_R";
    target = "R_";
    cout << sol.canChange(start, target) << "\n"; // 0

    start = "R_L__R__R_";
    target = "_L______RR";
    cout << sol.canChange(start, target) << "\n"; // 0

    return 0;
}

