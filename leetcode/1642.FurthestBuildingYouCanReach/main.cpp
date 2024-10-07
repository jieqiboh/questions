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
    int furthestBuilding1(vector<int>& heights, int bricks, int ladders) {
        // in ideal path: alw allocate bricks to smallest jmp and ladders to highest jmp
        priority_queue<int, vector<int>, greater<>> mhL; // minheap ladders
        priority_queue<int, vector<int>, greater<>> mhB; // minheap bricks
        int l = ladders;
        int b = bricks;

        for (int i = 0; i < heights.size() - 1; i++) {
            int dif = heights[i + 1] - heights[i];
            if (dif > 0) { // need jmp
                if (l > 0) { // ladders available
                    mhL.push(dif); l--;
                } else {
                    if (!mhL.empty() && mhL.top() < dif) { // need swap
                        int mhltop = mhL.top();
                        mhL.pop();
                        mhL.push(dif);
                        if (b >= mhltop) { // enough bricks
                            b -= mhltop;
                            mhB.push(mhltop);
                        } else {
                            return i; // cannot jmp anymore
                        }
                    } else {
                        if (b >= dif) {
                            b -= dif;
                            mhB.push(dif);
                        } else {
                            return i;
                        }
                    }
                }
            }
        }
        return heights.size() - 1;
    }

    bool canReach(vector<int>& heights, int bricks, int ladders, int i) {
        // whether idx i can be reached, assume i in bounds
        vector<int> jmps;
        for (int j = 0; j < i; j++) {
            int dif = heights[j + 1] - heights[j];
            if (dif > 0) {
                jmps.push_back(dif);
            }
        }

        sort(jmps.begin(), jmps.end());
        if (jmps.size() <= ladders) return true;
        for (int k = 0; k < jmps.size() - ladders; k++) {
            bricks -= jmps[k];
        }
        return bricks >= 0;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // in ideal path: alw allocate bricks to smallest jmp and ladders to highest jmp
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int mid = l + (r - l + 1) / 2;  // Move mid slightly upwards
            if (canReach(heights, bricks, ladders, mid)) {
                l = mid;  // Move l to mid
            } else {
                r = mid - 1;  // Move r left
            }
        }
        return l;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5;
    int ladders = 1;
    cout << sol.furthestBuilding(heights, bricks, ladders) << "\n"; // 4

    heights = {4,12,2,7,3,18,20,3,19};
    bricks = 10;
    ladders = 2;
    cout << sol.furthestBuilding(heights, bricks, ladders) << "\n"; // 7

    heights = {1};
    bricks = 0;
    ladders = 0;
    cout << sol.furthestBuilding(heights, bricks, ladders) << "\n"; // 0

    heights = {14,3,19,3};
    bricks = 17;
    ladders = 0;
    cout << sol.furthestBuilding(heights, bricks, ladders) << "\n"; // 0
    return 0;
}

