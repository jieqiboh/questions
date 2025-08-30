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
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i = 0;
        int j = 0;

        while (i < slots1.size() && j < slots2.size()) {
            vector<int> s1 = slots1[i];
            int start1 = s1[0];
            int end1 = s1[1];
            vector<int> s2 = slots2[j];
            int start2 = s2[0];
            int end2 = s2[1];

            vector<int> commonSlot = {max(start1, start2), min(end1, end2)};
            if (commonSlot[1] - commonSlot[0] + 1 > duration) {
                return {commonSlot[0], commonSlot[0] + duration};
            }

            // go next: move the one that ends earlier
            if (end1 < end2) {
                i++;
            } else if (end2 < end1) {
                j++;
            } else {
                j++;
                i++;
            }
        }
        return {};
    }
};


int main() {
    fast();
    Solution sol;
    vector<vector<int>> slots1 = {{10,50},{60,120},{140,210}};
    vector<vector<int>> slots2 = {{0,15},{60,70}};
    int duration = 8;
    vector<int> res = sol.minAvailableDuration(slots1, slots2, duration);
    cout << res[0] << " " << res[1] << "\n"; // 60, 68

    slots1 = {{0,2}};
    slots2 = {{1,3}};
    duration = 2;
    res = sol.minAvailableDuration(slots1, slots2, duration);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n"; // []

    slots1 = {{10,50},{60,120},{140,210}};
    slots2 = {{0,15},{60,70}};
    duration = 12;
    res = sol.minAvailableDuration(slots1, slots2, duration);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

