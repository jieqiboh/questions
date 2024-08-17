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
    int longestOnes(vector<int>& nums, int k) {
        int l = 0; // valid range is [l, r]
        int flips = k;
        int res = 0;
        for (int r = 0; r < nums.size(); r++) {
            // r is the current considered idx
            if (nums[r] == 0) {
                if (flips > 0) {
                    flips--;
                    res = max(res, r - l + 1);
                } else { // move l until a 0 is found
                    while (nums[l] != 0) {
                        l++;
                    }
                    l++;
                }
            } else {
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << sol.longestOnes(nums, k) << "\n"; // 6

    nums = {1,1,1,0,0,1,1,1,1,0};
    k = 2;
    cout << sol.longestOnes(nums, k) << "\n"; // 9

    nums = {0,0,0};
    k = 2;
    cout << sol.longestOnes(nums, k) << "\n"; // 2

    nums = {0};
    k = 2;
    cout << sol.longestOnes(nums, k) << "\n"; // 1

    nums = {1,1};
    k = 2;
    cout << sol.longestOnes(nums, k) << "\n"; // 2
    return 0;
}

