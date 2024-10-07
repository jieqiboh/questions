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
    int subarraySum(vector<int>& nums, int k) {
        // for a given prefix, there may be multiple occurrences
        // e.g. 0 in [1,-1,0] has 2 pos where it is the prefix sum
        unordered_map<int,int> rems; // contains existing prefix sums up till incl this idx
        rems.insert({0, 1}); // prefix sum, number of occurrences
        int curSum = 0;
        int cnt = 0;

        // for a valid subarray, range is [j, i], excluding j
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (rems.find(curSum - k) != rems.end()) {
                cnt+=rems[curSum - k];
            }
            rems[curSum]++;
        }
        return cnt;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,2,3};
    int k = 3;
    cout << sol.subarraySum(nums, k) << "\n"; // 2

    nums = {1,1,1};
    k = 2;
    cout << sol.subarraySum(nums, k) << "\n"; // 2

    nums = {1};
    k = 0;
    cout << sol.subarraySum(nums, k) << "\n"; // 0

    nums = {-1,-1,1};
    k = 0;
    cout << sol.subarraySum(nums, k) << "\n"; // 1

    nums = {1,-1,0};
    k = 0;
    cout << sol.subarraySum(nums, k) << "\n"; // 3
    return 0;
}

