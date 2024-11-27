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
    int triangleNumber(vector<int>& nums) {
        // triangle inequality: len of 2 sides must be > len of 3rd side
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int k = 2; k < nums.size(); k++) {
            for (int j = 1; j < k; j++) {
                for (int i = 0; i < j; i++) {
                    if (nums[i] + nums[j] > nums[k]) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,2,3,4};
    cout << sol.triangleNumber(nums) << "\n"; // 3

    nums = {4,2,3,4};
    cout << sol.triangleNumber(nums) << "\n"; // 4
    return 0;
}

