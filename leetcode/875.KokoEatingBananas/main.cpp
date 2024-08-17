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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 0;
        int r = piles[piles.size() - 1];

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canEat(piles, mid, h)) { // mid is enough
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool canEat(vector<int>& piles, int k, int h) {
        // given a certain k, can koko eat all the bananas within the time
        for (int i = 0; i < piles.size(); i++) {
            int pileSize = piles[i];
            while (pileSize > 0) {
                pileSize -= k;
                h--;
            }
        }
        return h >= 0;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << sol.minEatingSpeed(piles, h) << "\n"; // 4

    piles = {30,11,23,4,20};
    h = 5;
    cout << sol.minEatingSpeed(piles, h) << "\n"; // 30
    return 0;
}

