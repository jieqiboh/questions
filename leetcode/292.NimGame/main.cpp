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
    bool canWinNim(int n) {
        if (n <= 3) {
            return true;
        }
        return n % 4 != 0;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.canWinNim(4) << "\n"; // 0
    cout << sol.canWinNim(1) << "\n"; // 1

    return 0;
}

