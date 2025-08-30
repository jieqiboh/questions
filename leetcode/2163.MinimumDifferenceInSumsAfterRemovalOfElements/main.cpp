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
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> lhs; // contains the smallest n elements out of the 2n lhs elements top is largest
        priority_queue<int, vector<int>, greater<>> rhs; // contains the largest n elements out of the 2n rhs elements top is smallest

        vector<long long> leftSum;  // stores min sum from [0...i], where n <= i <= 2n
        vector<long long> rightSum; // stores max sum from [i...3n-1], where n <= i <= 2n

        long long curLeftSum = 0;
        for (int i = 0; i < nums.size() / 3; i++) {
            lhs.push(nums[i]);
            curLeftSum += nums[i];
        }
        leftSum.push_back(curLeftSum);

        long long curRightSum = 0;
        for (int i = nums.size() - 1; i >= nums.size() - nums.size() / 3; i--) {
            rhs.push(nums[i]);
            curRightSum += nums[i];
        }
        rightSum.push_back(curRightSum);

        long long res = INT64_MAX;

        // leftSum computation
        for (int i = nums.size() / 3; i < nums.size() - (nums.size() / 3); i++) {
            // i denotest the split point
            // lhs[0...i-1]
            // rhs[i...nums.size()-1]
            if (nums[i] < lhs.top()) {
                curLeftSum = curLeftSum - lhs.top() + nums[i];
                lhs.pop();
                lhs.push(nums[i]);
            }
            leftSum.push_back(curLeftSum);
        }

        // rightSum computation
        for (int i = nums.size() - nums.size() / 3 - 1; i >= nums.size() / 3; i--) {
            if (nums[i] > rhs.top()) {
                curRightSum = curRightSum - rhs.top() + nums[i];
                rhs.pop();
                rhs.push(nums[i]);
            }
            rightSum.push_back(curRightSum);
        }
        reverse(rightSum.begin(), rightSum.end());

        for (int i = 0; i < leftSum.size(); i++) {
            res = min(leftSum[i] - rightSum[i], res);
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {3,1,2};
    cout << sol.minimumDifference(nums) << "\n"; // -1

    nums = {7,9,5,8,1,3};
    cout << sol.minimumDifference(nums) << "\n"; // 1

    return 0;
}

