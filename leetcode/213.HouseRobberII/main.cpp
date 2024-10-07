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
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> includeFirst(nums.begin(), nums.end() - 1);
        vector<int> includeLast(nums.begin() + 1, nums.end());
        vector<int> cache1(nums.size(), -1);
        vector<int> cache2(nums.size(), -1);
        return max(helper(0, includeLast, cache1), helper(0, includeFirst, cache2));
    }
    int helper(int idx, vector<int>& nums, vector<int>& cache) {
        // idx is the cur house to consider robbing
        // includeLast is whether to consider robbing last house
        if (idx > nums.size() - 1) return 0;
        if (cache[idx] != -1) return cache[idx];
        int res = max(nums[idx] + helper(idx+2, nums, cache), helper(idx+1, nums, cache));
        cache[idx] = res;
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,3,2};
    cout << sol.rob(nums) << "\n"; // 3

    nums = {1,2,3,1};
    cout << sol.rob(nums) << "\n"; // 4

    nums = {1,2,3};
    cout << sol.rob(nums) << "\n"; // 3
    return 0;
}

