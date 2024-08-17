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
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        }

        int i = 0;
        int j = 1;
        int k = 1;

        for (int l = 3; l <= n; l++) {
            int tmp_i = i;
            int tmp_j = j;
            i = j;
            j = k;
            k = tmp_i + tmp_j + k;
        }
        return k;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.tribonacci(25) << "\n";

    return 0;
}

