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
    int countPrimes(int n) {
        vector<bool> A(n + 1, true);

        for (int i = 2; i <= sqrt(n); i++) {
            if (A[i]) {
                for (int j = pow(i, 2); j <= n; j+=i) {
                    A[j] = false;
                }
            }
        }
        vector<int> res = {};
        for (int i = 2; i < A.size() - 1; i++) {
            if (A[i]) res.push_back(i);
        }
        return res.size();
    }
};

int main() {
    fast();

    Solution sol;
    cout << sol.countPrimes(10) << "\n"; // 4

    return 0;
}

