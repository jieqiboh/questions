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
    int trailingZeroes(int n) {
        // do x/5 + x/5^2 + x/5^3 + ... = n
        int count = 1;
        int res = 0;

        int val = n / pow(5, count);
        while (val > 0) {
            res += val;
            count++;
            val = n / pow(5, count);
        }
        return count - 1;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.trailingZeroes(3) << "\n";
    cout << sol.trailingZeroes(5) << "\n";

    return 0;
}

