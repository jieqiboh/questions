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
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 32; j++) {
                cnt += (i & 1);
                i >>= 1;
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}

