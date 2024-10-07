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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 4 pointers
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {};

        for (int i = 0; i < static_cast<int>(nums.size()) - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip if duplicates
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip if duplicates
                int k = j + 1;
                int l = nums.size() - 1;
                long long sum;

                while (k < l) {
                    sum = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else { // sum == target
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k+1]) { // move k until diff nums[k] found
                            k++;
                        }
                        k++;
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
    vector<int> nums = {0, 0, 1, -1, 2, -2};
    int target = 0;
    vector<vector<int>> res = sol.fourSum(nums, target);
    for (vector<int> vi :res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    nums = {2,2,2,2,2};
    target = 8;
    res = sol.fourSum(nums, target);
    for (vector<int> vi :res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    nums = {0};
    target = 0;
    res = sol.fourSum(nums, target);
    for (vector<int> vi :res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

