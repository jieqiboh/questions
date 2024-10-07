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
    int minSubarray(vector<int>& nums, int p) {
        int total = 0;
        for (int num : nums) {
            total = (total + num) % p;
        }

        int targ = total % p; // subarray sum required to remove
        if (targ == 0) return 0;
        unordered_map<int,int> modMap; // maps prefixSum % p to idx
        modMap.insert({0, -1});
        // prefixSum at i = sum of all elems up to including nums[i]

        int curSum = 0;
        int minLen = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            curSum = (curSum + nums[i]) % p;
            modMap[curSum] = i;
            int needed = (curSum - targ + p) % p;
            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i - modMap[needed]);
            }
        }
        return (minLen == nums.size()) ? -1 : minLen;
    }
};


int main() {
    fast();
    Solution sol;
    vector<int> nums = {3,1,4,2};
    int p = 6;
    cout << sol.minSubarray(nums, p) << "\n"; // 1

    nums = {6,3,5,2};
    p = 9;
    cout << sol.minSubarray(nums, p) << "\n"; // 2

    nums = {1,2,3};
    p = 3;
    cout << sol.minSubarray(nums, p) << "\n"; // 0

    nums = {1,4};
    p = 3;
    cout << sol.minSubarray(nums, p) << "\n"; // 0

    nums = {1000000000,400000000};
    p = 3;
    cout << sol.minSubarray(nums, p) << "\n"; // 0
    return 0;
}

