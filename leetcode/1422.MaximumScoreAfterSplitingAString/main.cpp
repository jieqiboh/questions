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
    int maxScore(string s) {
        vector<int> ones(s.size());   // each idx is number of ones from RHS up till including that idx
        vector<int> zeroes(s.size()); // each idx is number of zeroes from LHS up till including that idx

        int zero_cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                zero_cnt++;
            }
            zeroes[i] = zero_cnt;
        }
        int one_cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                one_cnt++;
            }
            ones[i] = one_cnt;
        }

        int res = INT32_MIN;
        for (int i = 0; i < s.size() - 1; i++) {
            res = max(res, zeroes[i] + ones[i + 1]);
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}

