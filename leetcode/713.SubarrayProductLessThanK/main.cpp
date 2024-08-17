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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int i = 0;
        int j = 0;

        int curVal = nums[0];
        while (j < nums.size()) {
            if (curVal < k) {
                res += (j - i + 1);
                j++;
                if (j < nums.size()) curVal *= nums[j];
            } else {
                curVal /= nums[i];
                i++;
                if (i > j) {
                    j++;
                    if (j < nums.size()) curVal *= nums[j];
                }
            }
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {10,5,2,6};
    int k = 100;
    cout << sol.numSubarrayProductLessThanK(nums, k) << "\n"; // 8

    nums = {1,2,3};
    k = 0;
    cout << sol.numSubarrayProductLessThanK(nums, k) << "\n"; // 0
    return 0;
}

