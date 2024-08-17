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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 1;
        int res = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int maxval = 1;
            for (int j = i + 1; j <= nums.size() - 1; j++) {
                if (nums[i] < nums[j]) {
                    maxval = max(maxval, dp[j] + 1);
                }
            }
            dp[i] = maxval;
            res = max(maxval, res);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,2,4,3};
    cout << sol.lengthOfLIS(nums) << "\n"; // 3

    nums = {1,7,8,4,5,6,-1,9};
    cout << sol.lengthOfLIS(nums) << "\n"; // 5

    return 0;
}

