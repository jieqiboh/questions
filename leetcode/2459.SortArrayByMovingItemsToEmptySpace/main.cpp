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
    int sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> coordsStart(n); // to travel to achieve 0...
        vector<int> coordsEnd(n); // to travel to achieve ...0

        for (int i = 0; i < nums.size(); i++) {
            coordsStart[i] =  nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            coordsEnd[i] = (nums[i] - 1 + n) % n;
        }

        int zeroPos = 0;
        for (int i = 0; i < n; i++) if (nums[i] == 0) zeroPos = i;

        int startCycles = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] || coordsStart[i] == i) continue;
            int cur = i;
            bool containsZero = false;
            int cycleLen = 0;
            while (!visited[cur]) {
                visited[cur] = true;
                if (cur == zeroPos) containsZero = true;
                cycleLen++;
                cur = coordsStart[cur];
            }
            startCycles += containsZero ? cycleLen - 1 : cycleLen + 1;
        }

        int endCycles = 0;
        fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < n; i++) {
            if (visited[i] || coordsEnd[i] == i) continue;
            int cur = i;
            bool containsZero = false;
            int cycleLen = 0;
            while (!visited[cur]) {
                visited[cur] = true;
                if (cur == zeroPos) containsZero = true;
                cycleLen++;
                cur = coordsEnd[cur];
            }
            endCycles += containsZero ? cycleLen - 1 : cycleLen + 1;
        }
        return min(startCycles, endCycles);
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {4,2,0,3,1};
    cout << sol.sortArray(nums);

    return 0;
}

