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
    int maxValue(int n, int index, int maxSum) {
        if (n == 1) return maxSum; // edge case
        vector<int> res(n, 0);
        // multiple passthroughs of res, incrementing when possible
        res[index] = 1;
        maxSum--;
        while (maxSum > 0) {
            for (int i = 0; i < res.size(); i++) {
                if (i != index) {
                    int left = (i-1 >= 0) ? res[i-1] : 0;
                    int right = (i+1 < res.size()) ? res[i+1] : 0;
                    if ((left > 0 || right > 0) && maxSum > 0) {
                        res[i]++;
                        maxSum--;
                    }
                }
            }
            int left = (index-1 >= 0) ? res[index-1] : 1;
            int right = (index+1 < res.size()) ? res[index+1] : 1;
            if (abs(res[index] - left) == 0 && abs(res[index] - right) == 0 && maxSum > 0) {
                res[index]++;
                maxSum--;
            }
        }
        return res[index];
    }
};

int main() {
    fast();
    Solution sol;
//    cout << sol.maxValue(4,2,6) << "\n"; // 2
//
//    cout << sol.maxValue(4,2,4) << "\n"; // 2

    cout << sol.maxValue(4,0,6) << "\n"; // 3

    return 0;
}

