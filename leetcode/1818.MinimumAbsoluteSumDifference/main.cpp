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
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        vector<int> originalSums;
        for (int i = 0; i < nums1.size(); i++) {
            originalSums.push_back(abs(nums1[i] - nums2[i]));
        }

        vector<int> sortedNums1 = nums1;
        sort(sortedNums1.begin(), sortedNums1.end());

        long long maxImprovement= 0;
        for (int i = 0; i < nums2.size(); i++) {
            // for each nums2 val, find the closest val in nums1 to it and compute the difference
            int closestNum1 = closest(nums2[i], sortedNums1);
            long long improvement = originalSums[i] - abs(closestNum1 - nums2[i]);
            maxImprovement = max(improvement, maxImprovement);
        }

        long long originalSum = accumulate(originalSums.begin(), originalSums.end(), 0LL);
        return (originalSum - maxImprovement) % (long long)(1e9 + 7);
    }

    int closest(int x, vector<int> &arr) {
        // given an int x, find the value in sorted nums1 that is closest to it
        auto it = lower_bound(arr.begin(), arr.end(), x);

        int closest;
        if (it == arr.begin()) {
            closest = *it; // x is smaller than all elements
        } else if (it == arr.end()) {
            closest = arr.back(); // x is larger than all elements
        } else {
            int bigger = *it;
            int smaller = *(it - 1);
            // pick the closer one
            closest = (abs(bigger - x) < abs(smaller - x)) ? bigger : smaller;
        }
        return closest;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums1 = {1,7,5};
    vector<int> nums2 = {2,3,5};
    cout << sol.minAbsoluteSumDiff(nums1, nums2) << "\n"; // 3

    nums1 = {1,10,4,4,2,7};
    nums2 = {9,3,5,1,7,4};
    cout << sol.minAbsoluteSumDiff(nums1, nums2) << "\n"; // 20

    return 0;
}

