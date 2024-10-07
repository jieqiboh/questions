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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int minFlips(int a, int b, int c) {
        // for every bit, extract the LSB and compare to see how many bits need flipping
        // 0 0 1 - 1
        // 0 1 0 - 1
        // 1 1 0 - 2
        // 0

        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;

            if (abit == 0 && bbit == 0 & cbit == 1) {
                cnt++;
            } else if (cbit == 0 && ((abit == 1 && bbit == 0) || (abit == 0 && bbit == 1))) {
                cnt++;
            } else if (abit == 1 && bbit == 1 && cbit == 0) {
                cnt+=2;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};

int main() {
    fast();
    Solution sol;
    int a = 2;
    int b = 6;
    int c = 5;
    cout << sol.minFlips(a,b,c) << "\n";

    return 0;
}

