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
    bool isOneBitCharacter(vector<int>& bits) {
        vector<bool> dp(bits.size() + 1, false);

        if (bits[bits.size() - 1] != 0) {
            return false;
        } else {
            dp[bits.size() - 1] = true;
        }

        // [ T F T .... ]
        for (int i = bits.size() - 2; i >= 0; i--) {
            if (bits[i] == 1) {
                dp[i] = dp[i + 2];
            } else { // bits[i] == 0
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> bits = {1,1,1,0};
    cout << sol.isOneBitCharacter(bits) << "\n"; // 0

    bits = {1,0,0};
    cout << sol.isOneBitCharacter(bits) << "\n"; // 1

    bits = {0,0,0};
    cout << sol.isOneBitCharacter(bits) << "\n"; // 1

    bits = {0,1,0};
    cout << sol.isOneBitCharacter(bits) << "\n"; // 0
    return 0;
}

