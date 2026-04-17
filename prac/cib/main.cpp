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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
    vector<vector<int>> cache;
public:
    int ms(vector<int>& nums, int i, int j) {
        // return the max score the current picking player can get given options i and j
        if (i == j) {
            return nums[i];
        }
        int leftRemSum = 0;
        for (int k = i + 1; k <= j; k++) leftRemSum += nums[k];
        int rightRemSum = 0;
        for (int k = i; k <= j-1; k++) rightRemSum += nums[k];

        int pickLeft = nums[i] - ms(nums, i+1, j) + leftRemSum;
        int pickRight = nums[j] - ms(nums,i, j-1) + rightRemSum;
        return max(pickLeft, pickRight);
    }

    int ms_cache(vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        // return the max score the current picking player can get given options i and j
        if (i == j) {
            return nums[i];
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int leftRemSum = 0;
        for (int k = i + 1; k <= j; k++) leftRemSum += nums[k];
        int rightRemSum = 0;
        for (int k = i; k <= j-1; k++) rightRemSum += nums[k];

        int pickLeft = nums[i] - ms(nums, i+1, j) + leftRemSum;
        int pickRight = nums[j] - ms(nums,i, j-1) + rightRemSum;
        int res = max(pickLeft, pickRight);
        memo[i][j] = res;
        return memo[i][j];
    }
};

int main() {
    fast();

    vector<int> nums = {1,3};
    Solution sol;
    cout << sol.ms_cache(nums, 0, nums.size() - 1) << "\n"; // 3

    nums = {1,3,6,9};
    cout << sol.ms(nums, 0, nums.size() - 1) << "\n"; // 12

    nums = {1,9,10,5,6,4};
    cout << sol.ms(nums, 0, nums.size() - 1) << "\n"; // 18
    return 0;
}

