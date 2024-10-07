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
    int shipWithinDays(vector<int>& weights, int days) {
        // binary search
        int l = 0;
        int r = INT32_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(weights, days, mid)) {
                // mid is >= min capacity
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    bool isValid(vector<int>& weights, int days, int n) {
        // checks if given n capacity per day, is able to ship all weights within days
        int j = 0; // current weight
        for (int i = 0; i < days; i++) {
            // per day, ship as many weights as possible
            int cap = n;
            while (cap - weights[j] >= 0 && j < weights.size()) {
                cap -= weights[j];
                j++;
            }
        }
        if (j == weights.size()) return true;
        return false;
    }
};

int main() {
    fast();
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    Solution sol;
    cout << sol.isValid(weights, days, 15) << "\n"; // 1
    cout << sol.isValid(weights, days, 14) << "\n"; // 0
    cout << sol.isValid(weights, days, 13) << "\n"; // 0
    cout << sol.shipWithinDays(weights, days) << "\n"; // 15

    weights = {3,2,2,4,1,4};
    days = 3;
    cout << sol.shipWithinDays(weights, days) << "\n"; // 6
    return 0;
}

