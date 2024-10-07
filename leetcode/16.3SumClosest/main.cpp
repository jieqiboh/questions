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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int cur = INT32_MIN;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = target - sum;
                if (abs(diff) < abs(target - cur)) cur = sum;
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return cur;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    cout << sol.threeSumClosest(nums, target) << "\n";

    return 0;
}

