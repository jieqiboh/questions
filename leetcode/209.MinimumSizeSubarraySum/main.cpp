#include <iostream>
#include <numeric>
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < target) return 0;

        int l = 0; int r = 0; // [l,r] denotes the cur considered range
        int val = nums[0]; // val equals the sum of nums[l,r] at the start of every loop
        int cur_min = 1;
        int total_min = INT32_MAX;

        while (r < nums.size() && l <= r) {
            if (val >= target) {
                total_min = min(cur_min, total_min);
            }
            if (val > target) {
                val -= nums[l];
                l++;
                cur_min--;
            } else {
                r++;
                if (r < nums.size()) {
                    val += nums[r];
                    cur_min++;
                }
            }
        }
        total_min = (total_min == INT32_MAX) ? 0 : total_min;
        return total_min;
    }
};

int main() {
    fast();

    Solution  sol;
    vector<int> nums = {2,3,1,2,4,3};
    cout << sol.minSubArrayLen(7, nums) << "\n"; // 2

    nums = {2,16,14,15};
    cout << sol.minSubArrayLen(20, nums) << "\n"; // 2

    nums = {10,2,3};
    cout << sol.minSubArrayLen(6, nums) << "\n"; // 1

    nums = {10,2,3};
    cout << sol.minSubArrayLen(60, nums) << "\n"; // 0


    return 0;
}

