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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int> groups; // maps number to their group

        vector<int> startPos; // start pos idx of each group
        startPos.push_back(0);
        int curMin = sorted[0]; // current minVal of group
        int curMax = sorted[0]; // current maxVal of group
        int curGroup = 0;
        for (int i = 0; i < sorted.size(); i++) {
            if (abs(sorted[i] - curMin) <= limit || abs(sorted[i] - curMax) <= limit) {
                curMin = min(curMin, sorted[i]);
                curMax = max(curMax, sorted[i]);
            } else {
                curMin = sorted[i]; // update minVal of group
                curMax = sorted[i]; // update maxVal of group
                curGroup++;         // update curGroup to new one
                startPos.push_back(i);
            }
            groups[sorted[i]] = curGroup;
        }

        unordered_map<int,int> idxmap; // maps original idx to group
        for (int i = 0; i < nums.size(); i++) {
            idxmap[i] = groups[nums[i]];
        }

        vector<int> pos(curGroup + 1, 0); // cur pos of idx in each group
        for (int i = 0; i < nums.size(); i++) {
            int grp = idxmap[i];
            nums[i] = sorted[pos[grp] + startPos[grp]];
            pos[grp]++;
        }
        return nums;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,7,6,18,2,1};
    int limit = 3;
    vector<int> res = sol.lexicographicallySmallestArray(nums, limit);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

