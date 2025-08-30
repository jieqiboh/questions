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
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1;
        int curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { // strictly increasing
                curLen++;
            } else {
                maxLen = max(maxLen, curLen);
                curLen = 1;
            }
        }
        maxLen = max(maxLen, curLen);
        curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) { // strictly decreasing
                curLen++;
            } else {
                maxLen = max(maxLen, curLen);
                curLen = 1;
            }
        }
        maxLen = max(maxLen, curLen);
        return maxLen;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,4,3,3,2};
    cout << sol.longestMonotonicSubarray(nums) << "\n"; // 2

    nums = {3,3,3,3};
    cout << sol.longestMonotonicSubarray(nums) << "\n"; // 1
    return 0;
}

