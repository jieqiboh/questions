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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = INT_MAX;

        while (l < r) {
            int mid = ((r - l) / 2) + l;
            if (canShip(days, mid, weights)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool canShip(int days, int capacity, vector<int>& weights) {
        // assume all weights < capacity
        int neededDays = 1;
        int curCap = capacity;
        for (int x : weights) {
            if (curCap - x >= 0) {
                curCap -= x;
            } else {
                curCap = capacity;
                neededDays++;
            }
        }
        return neededDays <= days;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> weights = {2,4,6,1,3,10};
    int days = 4;
    cout << sol.shipWithinDays(weights, days) << "\n";

    return 0;
}

