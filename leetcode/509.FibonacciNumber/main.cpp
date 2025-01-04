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
    int fib(int n) {
        int a = 0;
        int b = 1;

        if (n == 0) {
            return a;
        } else if (n == 1) {
            return b;
        }

        for (int i = 2; i <= n; i++) {
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return b;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.fib(2) << "\n"; // 1

    cout << sol.fib(3) << "\n"; // 2

    cout << sol.fib(4) << "\n"; // 3
    return 0;
}

