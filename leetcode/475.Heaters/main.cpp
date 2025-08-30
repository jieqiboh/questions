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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());

        int l = 0;
        int r = INT_MAX;
        while (l <= r) {
            int mid = (r + l) / 2;
            if (canHeat(mid, heaters, houses)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool canHeat(int radius, vector<int>& heaters, vector<int>& houses) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (int heater : heaters) {
            pq.push({heater - radius, heater + radius});
        }

        for (int i = 0; i < houses.size(); i++) {
            int housePos = houses[i];
            while (!(housePos >= pq.top().first && housePos <= pq.top().second)) {
                pq.pop();
                if (pq.empty()) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> heaters = {1,4};
    vector<int> houses = {1,2,3,4};
    cout << sol.findRadius(houses, heaters) << "\n"; // 1

    heaters = {2};
    houses = {1,2,3};
    cout << sol.findRadius(houses, heaters) << "\n"; // 1

    heaters = {2};
    houses = {1,5};
    cout << sol.findRadius(houses, heaters) << "\n"; // 3
    return 0;
}

