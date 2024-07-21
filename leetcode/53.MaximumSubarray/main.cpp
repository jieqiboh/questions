#include <climits>
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
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (cur_sum < 0) { // reset cur_sum
                cur_sum = nums[i];
            } else { // add to subarray
                cur_sum += nums[i];
            }
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum; 
    }
};

int main() {
    fast();

    Solution sol;

    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums1) << "\n"; // 6

    vector<int> nums2 = {-2};
    cout << sol.maxSubArray(nums2) << "\n"; // -2

    vector<int> nums3 = {-2,3,-5,10};
    cout << sol.maxSubArray(nums3) << "\n"; //10 

    return 0;
}

