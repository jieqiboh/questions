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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // contains min elems value, index of array in nums
        priority_queue<int> pqMax; // contains max elems
        vector<int> idxs(nums.size(), 0); // contains idxs at each array

        int res = INT32_MAX;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) { // init pq
            vector<int> v = nums[i];
            int idx = idxs[i]; // index for that array
            pq.push({v[idx], i});
            pqMax.push(v[idx]);
        }
        if (pqMax.top() - pq.top().first < res) {
            res = pqMax.top() - pq.top().first;
            ans = {pq.top().first, pqMax.top()};
        }

        while (true) {
            pair<int,int> minP = pq.top();
            int i = minP.second;
            vector<int> v = nums[i];

            idxs[i] += 1;
            if (idxs[i] >= v.size()) break; // last idx of an array reached
            pq.pop();

            int idx = idxs[i];
            pq.push({v[idx], i});
            pqMax.push(v[idx]);

            if (pqMax.top() - pq.top().first < res) {
                res = pqMax.top() - pq.top().first;
                ans = {pq.top().first, pqMax.top()};
            }
        }
        return ans;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> res = sol.smallestRange(nums);
    cout << res[0] << " " << res[1] << "\n"; // 20 24

    nums = {{1,2,3},{1,2,3},{1,2,3}};
    res = sol.smallestRange(nums);
    cout << res[0] << " " << res[1] << "\n"; // 1 1

    nums = {{1},{3},{5}};
    res = sol.smallestRange(nums);
    cout << res[0] << " " << res[1] << "\n"; // 1 5
    return 0;
}

