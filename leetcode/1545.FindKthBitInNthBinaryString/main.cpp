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
    string invRev(string x) {
        int sz = x.size();
        for (int i = 0; i < sz / 2; i++) { // reverse
            swap(x[i], x[sz - i - 1]);
        }
        for (int i = 0; i < sz; i++) { // invert
            if (x[i] == '0') {
                x[i] = '1';
            } else {
                x[i] = '0';
            }
        }
        return x;
    }
    char findKthBit(int n, int k) {
        string s = "0";

        string newS = "0";

        for (int i = 0; i < n - 1; i++) {
            newS = s + "1" + invRev(s);
            s = newS;
        }
        return newS[k - 1];
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.findKthBit(3, 1) << "\n"; // '0'

    cout << sol.findKthBit(4, 11) << "\n"; // '1'

    cout << sol.findKthBit(1, 1) << "\n"; // '1'
    return 0;
}

