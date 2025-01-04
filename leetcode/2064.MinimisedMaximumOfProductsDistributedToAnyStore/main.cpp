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
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0;
        int r = *max_element(quantities.begin(), quantities.end());
        while (l <= r) {
            int mid = (r + l) / 2;
            if (canDistribute(mid, n, quantities)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool canDistribute(int x, int n, vector<int>& quantities) {
        // Pointer to the first not fully distributed product type
        int j = 0;
        // Remaining quantity of the jth product type
        int remaining = quantities[j];

        // Loop through each store
        for (int i = 0; i < n; i++) {
            // Check if the remaining quantity of the jth product type
            // can be fully distributed to the ith store
            if (remaining <= x) {
                // If yes, move the pointer to the next product type
                j++;
                // Check if all products have been distributed
                if (j == quantities.size()) {
                    return true;
                } else {
                    remaining = quantities[j];
                }
            } else {
                // Distribute the maximum possible quantity (x) to the ith store
                remaining -= x;
            }
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> quantities = {11,6};
    int n = 6;
    cout << sol.minimizedMaximum(n, quantities) << "\n"; // 3

    quantities = {15, 10, 10};
    n = 7;
    cout << sol.minimizedMaximum(n, quantities) << "\n"; // 5

    quantities = {5,7};
    n = 2;
    cout << sol.minimizedMaximum(n, quantities) << "\n"; // 7

    return 0;
}

