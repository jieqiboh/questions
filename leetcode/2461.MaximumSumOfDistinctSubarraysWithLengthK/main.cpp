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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0;
        ll curSum = 0;
        unordered_map<int,int> freq; // maps num to freq
        for (int j = 0; j < k; j++) {
            curSum += nums[j];
            freq[nums[j]]++;
        }
        int j = k - 1;
        ll res = 0;
        if (freq.size() == k) {
            res = max(curSum, res);
        }

        while (j < nums.size() - 1) {
            curSum -= nums[i];
            freq[nums[i]]--;
            if (freq[nums[i]] == 0) {
                freq.erase(nums[i]); // erase if frequency of nbr is 0
            }
            j++;
            i++;
            curSum += nums[j];
            freq[nums[j]]++;
            if (freq.size() == k) {
                res = max(curSum, res);
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    cout << sol.maximumSubarraySum(nums, k) << "\n"; // 15

    nums = {4,4,4};
    k = 0;
    cout << sol.maximumSubarraySum(nums, k) << "\n"; // 0

    nums = {1,2,2};
    k = 2;
    cout << sol.maximumSubarraySum(nums, k) << "\n"; // 3

    nums = {9,9,9,1,2,3};
    k = 3;
    cout << sol.maximumSubarraySum(nums, k) << "\n"; // 12

    return 0;
}

