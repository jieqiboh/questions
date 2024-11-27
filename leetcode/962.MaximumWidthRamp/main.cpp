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
    int maxWidthRamp(vector<int>& nums) {
        vector<int> idxes(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            idxes[i] = i;
        }
        sort(idxes.begin(),idxes.end(), [&nums](int& a, int&b) {
            return nums[a] < nums[b];
        });

        int res = 0;
        int minIdx = idxes.size();
        for (int i = 0; i < idxes.size(); i++) {
            res = max(res, idxes[i] - minIdx);
            minIdx = min(minIdx, idxes[i]);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {6,0,8,2,1,5};
    cout << sol.maxWidthRamp(nums) << "\n"; // 4

    nums = {5,5};
    cout << sol.maxWidthRamp(nums) << "\n"; // 1

    nums = {5,1};
    cout << sol.maxWidthRamp(nums) << "\n"; // 0

    nums = {9,8,1,0,1,9,4,0,4,1};
    cout << sol.maxWidthRamp(nums) << "\n"; // 7

    nums = {2,2,1};
    cout << sol.maxWidthRamp(nums) << "\n"; // 1
    return 0;
}

