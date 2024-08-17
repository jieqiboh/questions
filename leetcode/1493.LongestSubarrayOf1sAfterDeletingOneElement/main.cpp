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
    int longestSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        // largest subarray containing only 1 0
        int l = 0; // [l,r] is a valid range at the start of each loop

        int res = 0;
        bool hasZero = false;
        if (nums[0] == 0) hasZero = true;
        for (int r = 1; r < nums.size(); r++) {
            // r is cur considered idx
            if (nums[r] == 0 && hasZero) { // range already has a zero
                while (nums[l] != 0) {
                    l++;
                }
                l++;
            } else if (nums[r] == 0 && !hasZero) { // range doesn't have zero yet
                hasZero = true;
                res = max(res, r - l + 1);
            } else {
                res = max(res, r - l + 1);
            }
        }
        return res == 0 ? 0 : res - 1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,1,0,1};
    cout << sol.longestSubarray(nums) << "\n"; // 3

    nums = {0,1,1,1,0,1,1,0,1};
    cout << sol.longestSubarray(nums) << "\n"; // 5

    nums = {1,1,1};
    cout << sol.longestSubarray(nums) << "\n"; // 2
    return 0;
}

