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
    int maxProduct(vector<int>& nums) {
        vector<double> right(nums.size(), 1);
        vector<double> left(nums.size(), 1);
        if (nums.size() == 1) return nums[0];

        double maxVal = INT32_MIN;

        double pdt = 1;
        for (int i = 0; i < right.size(); i++) {
            pdt *= nums[i];
            right[i] = pdt;
            maxVal = max(maxVal, right[i]);

            if (nums[i] == 0) {
                pdt = 1;
            }
        }

        pdt = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            pdt *= nums[i];
            left[i] = pdt;
            maxVal = max(maxVal, left[i]);
            if (nums[i] == 0) {
                pdt = 1;
            }
        }

        return maxVal;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    cout << sol.maxProduct(nums) << "\n"; // 6

    nums = {-2,0,-1};
    cout << sol.maxProduct(nums) << "\n"; // 0

    nums = {0,2};
    cout << sol.maxProduct(nums) << "\n"; // 2
    return 0;
}

