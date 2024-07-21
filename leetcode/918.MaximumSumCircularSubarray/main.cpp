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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    // Note: This has been augmented to get the first index of the max circular subarray
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        cout << "total_sum is: " << total_sum << "\n";
        int max_subarray = maxSubArray(nums).first;
        int max_subarray_idx = maxSubArray(nums).second;
        cout << "max subarray is: " << max_subarray << "\n";
        int min_subarray = minSubArray(nums).first;
        int min_subarray_idx = minSubArray(nums).second;
        cout << "min subarray is: " << min_subarray << "\n";

        // if the max contiguous subarray is negative, this means all elements are negative and it basically is just the
        // smallest element in the array so the circular max subarray is guaranteed to be less than or equal to it
        int res = max_subarray < 0 ? max_subarray : max(max_subarray, total_sum - min_subarray);

        return res;
    }

    pair<int, int> maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = INT32_MIN;
        int first_idx, last_idx;

        for (int i = 0; i < nums.size(); i++) {
            if (cur_sum < 0) { // reset cur_sum
                cur_sum = nums[i];
                first_idx = i; // to track first index
            } else { // add to subarray
                cur_sum += nums[i];
            }
            max_sum = max(cur_sum, max_sum);
        }
        return make_pair(max_sum, first_idx);
    }

    pair<int, int> minSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int min_sum = INT32_MAX;
        int first_idx;

        for (int i = 0; i < nums.size(); i++) {
            if (cur_sum > 0) { // reset cur_sum
                cur_sum = nums[i];
                first_idx = i;
            } else { // add to subarray
                cur_sum += nums[i];
                first_idx++; // add since we actually want the maxSubarray's first idx
            }
            min_sum = min(cur_sum, min_sum);
        }
        return make_pair(min_sum, first_idx);
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums1 = {-3,-2,-3};
    cout << sol.maxSubarraySumCircular(nums1) << "\n"; // 3

    return 0;
}

