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
    int minimumMountainRemovals(vector<int>& nums) {
        // for each idx, compute LDS from idx to end, from left to right
        int res = INT32_MAX;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int tot = 0;
            tot += LDS_r(nums, i);
            tot += LDS_l(nums, i);
            tot += 1;
            res = min(res, n - tot);
        }
        return res;
    }

    int LDS_r(vector<int>& nums, int start) {
        return LDS_right(nums, start + 1, nums[start]);
    }

    int LDS_right(vector<int>& nums, int i, int prev) {
        // consider i in subsequence
        if (i >= nums.size()) {
            return 0;
        } else {
            if (nums[i] < prev) {
                return max(1 + LDS_right(nums, i + 1, nums[i]), LDS_right(nums, i + 1, prev));
            } else {
                return LDS_right(nums, i + 1, prev);
            }
        }
    }

    int LDS_l(vector<int>& nums, int start) {
        return LDS_left(nums, start - 1, nums[start]);
    }

    int LDS_left(vector<int>& nums, int i, int prev) {
        if (i < 0) {
            return 0;
        } else {
            if (nums[i] < prev) {
                return max(1 + LDS_left(nums, i - 1, nums[i]), LDS_left(nums, i - 1, prev));
            } else {
                return LDS_left(nums, i - 1, prev);
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,3,1};
    cout << sol.minimumMountainRemovals(nums) << "\n"; // 0

    nums = {2,1,1,5,6,2,3,1};
    cout << sol.minimumMountainRemovals(nums) << "\n"; // 3
    return 0;
}

