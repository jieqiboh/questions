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
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<ll,ll> m; // stores the sq streak starting at each number

        ll res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            // compute sq streak starting from this num
            ll cur = nums[i];
            m[cur] = (ll)1; // init to 1
            if (m.find(pow(cur, (ll)2)) != m.end()) {
                m[cur] += m[pow(cur, (ll)2)];
            }
            res = max(res, m[cur]);
        }

        return res >= 2 ? res : -1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {4,3,6,16,8,2};
    cout << sol.longestSquareStreak(nums) << "\n"; // 3

    nums = {2,3,5,6,7};
    cout << sol.longestSquareStreak(nums) << "\n"; // -1
    return 0;
}

