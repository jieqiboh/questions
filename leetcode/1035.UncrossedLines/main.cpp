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
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return mul(0, 0, nums1, nums2, dp);
    }

    int mul(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if (i >= nums1.size() || j >= nums2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Skip the current element at nums1[i]
        int noTake = mul(i + 1, j, nums1, nums2, dp);

        // Take the current element at nums1[i] if possible
        int take = 0;
        int k = j;
        while (k < nums2.size() && nums2[k] != nums1[i]) {
            k++;
        }
        if (k < nums2.size()) {
            take = 1 + mul(i + 1, k + 1, nums1, nums2, dp);
        }

        dp[i][j] = max(noTake, take);
        return dp[i][j];
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums1 = {1,4,2};
    vector<int> nums2 = {1,2,4};
    cout << sol.maxUncrossedLines(nums1, nums2) << "\n"; // 2

    nums1 = {2,5,1,2,5};
    nums2 = {10,5,2,1,5,2};
    cout << sol.maxUncrossedLines(nums1, nums2) << "\n"; // 3

    nums1 = {1,3,7,1,7,5};
    nums2 = {1,9,2,5,1};
    cout << sol.maxUncrossedLines(nums1, nums2) << "\n"; // 2

    return 0;
}

