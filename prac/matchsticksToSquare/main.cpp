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
    bool makesquare(vector<int>& matchsticks) {
        // for every stick, we can place it in one of the 4 sides
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) return false;
        sort(matchsticks.rbegin(), matchsticks.rend()); // descending
        return dfs(0, matchsticks, 0, 0, 0, 0, totalLen / 4);
    }

    bool dfs(int i, vector<int>& matchsticks, int lenOne, int lenTwo, int lenThree, int lenFour, int sideLen) {
        if (i >= matchsticks.size()) {
            if (lenOne == sideLen && lenTwo == sideLen && lenThree == sideLen && lenFour == sideLen) {
                return true;
            }
            return false;
        }
        if (lenOne > sideLen || lenTwo > sideLen || lenThree > sideLen || lenFour > sideLen) return false;

        int curStick = matchsticks[i];
        bool one = false; bool two = false; bool three = false; bool four = false;
        unordered_set<int> tried;

        if (!tried.count(lenOne) && lenOne + curStick <= sideLen) {
            tried.insert(lenOne);
            if (dfs(i+1, matchsticks, lenOne + curStick, lenTwo, lenThree, lenFour, sideLen)) return true;
        }
        if (!tried.count(lenTwo) && lenTwo + curStick <= sideLen) {
            tried.insert(lenTwo);
            if (dfs(i+1, matchsticks, lenOne, lenTwo + curStick, lenThree, lenFour, sideLen)) return true;
        }
        if (!tried.count(lenThree) && lenThree + curStick <= sideLen) {
            tried.insert(lenThree);
            if (dfs(i+1, matchsticks, lenOne, lenTwo, lenThree + curStick, lenFour, sideLen)) return true;
        }
        if (!tried.count(lenFour) && lenFour + curStick <= sideLen) {
            tried.insert(lenFour);
            if (dfs(i+1, matchsticks, lenOne, lenTwo, lenThree, lenFour + curStick, sideLen)) return true;
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> matchsticks = {1,3,4,2,2,4};
    cout << sol.makesquare(matchsticks) << "\n"; // 1

    matchsticks = {1,3,7};
    cout << sol.makesquare(matchsticks) << "\n"; // 0
    return 0;
}

