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
    string predictPartyVictory(string senate) {
        queue<int> rad;
        queue<int> dir;

        int n = senate.length();
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'D') {
                dir.push(i);
            } else if (senate[i] == 'R') {
                rad.push(i);
            }
        }
        
        while (!rad.empty() && !dir.empty()) {
            int rad_sen = rad.front();
            rad.pop();
            int dir_sen = dir.front();
            dir.pop();

            if (rad_sen < dir_sen) {
                rad.push(n);
            } else if (dir_sen < rad_sen) {
                dir.push(n);
            }
            n++;
        }

        return rad.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    fast();
    Solution sol;
    string senate = "RDD";
    cout << sol.predictPartyVictory(senate) << "\n";

    return 0;
}

