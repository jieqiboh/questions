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
        int l = 0; // [l, r] is the current considered range
        int r = 0;
        int val = nums[0]; // val of the range
        int minLen = INT32_MAX;

        while (r < nums.size() && l <= r) {
            if (val < target) {
                r++;
                if (r < nums.size()) val += nums[r];
            } else { // val >= target
                minLen = min(minLen, r - l + 1);
                val -= nums[l];
                l++; // try to shorten the range
            }
        }
        return minLen == INT32_MAX ? 0 : minLen;
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

