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
    long long minimumSteps(string s) {
        // min steps to move all black balls to the right
        int blkCnt = 0; // number of black chars
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') blkCnt++;
        }
        int steps = 0;
        // 10100
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                steps += s.length() - blkCnt - i;
                blkCnt--;
            }
        }
        return steps;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "101";
    cout << sol.minimumSteps(s) << "\n"; // 1

    s = "100";
    cout << sol.minimumSteps(s) << "\n"; // 2

    s = "0111";
    cout << sol.minimumSteps(s) << "\n"; // 0

    s = "10100";
    cout << sol.minimumSteps(s) << "\n"; // 5
    return 0;
}

