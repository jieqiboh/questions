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
    int findKthNumber(int n, int k) {
        int cur = 1;
        while () {
            int steps = countSteps(cur, cur + 1, n);
            if (steps > k) { // explore down
                cur *= 10;
            } else {
                cur++; // explore right
                k -= steps;
            }
        }
    }
    int countSteps(int prefix1, int prefix2, int max) {
        // counts the number of valid steps between prefix1 and max
        int steps = 0;
        while (max > prefix1) {
            steps += min(max + 1, prefix2) - prefix1; // number of steps in this layer
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
//    vector<int> lexicalOrder(int n, int& k) {
//        vector<int> res;
//        for (int i = 1; i < 10; i++) {
//            dfs(i, res, n, k);
//        }
//        return res;
//    }
//    void dfs(int i, vector<int>& res, int max, int& maxK) {
//        // does a dfs, adding new numbers while <= max and count <= k
//        if (i > max) return;
//        if (maxK <= 0) return;
//        res.push_back(i);
//        maxK--;
//        for (int j = 0; j < 10; j++) {
//            int newI = i * 10 + j;
//            dfs(newI, res, max, maxK);
//        }
//    }

};

int main() {
    fast();
    Solution sol;
    cout << sol.findKthNumber(13, 2) << "\n";

    return 0;
}

