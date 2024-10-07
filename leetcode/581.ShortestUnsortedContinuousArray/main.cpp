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
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> maxsofar(nums.size()); // l2r
        vector<int> minsofar(nums.size()); // r2l

        int curMax = INT32_MIN;
        for (int i = 0; i < nums.size();i++) {
            curMax = max(curMax, nums[i]);
            maxsofar[i] = curMax;
        }
        int curMin = INT32_MAX;
        for (int i = nums.size() - 1; i >= 0; i--) {
            curMin = min(curMin, nums[i]);
            minsofar[i] = curMin;
        }

        int i = 0;
        while (i < nums.size() && nums[i] <= minsofar[i] && nums[i] >= maxsofar[i]) i++;
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] <= minsofar[j] && nums[j] >= maxsofar[j]) j--;
        return (i >= j) ? 0 : j - i + 1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,6,4,8,10,9,15};
    cout << sol.findUnsortedSubarray(nums) << "\n"; // 5

    nums = {1,2,3,4};
    cout << sol.findUnsortedSubarray(nums) << "\n"; // 0

    nums = {1};
    cout << sol.findUnsortedSubarray(nums) << "\n"; // 0
    return 0;
}

