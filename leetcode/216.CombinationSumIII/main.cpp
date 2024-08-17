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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> tempList;
        backtrack(res, nums, tempList, 0, 0, k, n);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& tempList, int start, int curSum, int k, int n) {
        if (curSum == n && tempList.size() == k) {
            res.push_back(tempList);
        } else if (curSum > n || tempList.size() > k) { // no need to continue
            return;
        } else {
            for (int i = start; i < nums.size(); i++) {
                tempList.push_back(nums[i]);
                curSum += nums[i];

                backtrack(res, nums, tempList, i + 1, curSum, k, n);

                tempList.pop_back();
                curSum -= nums[i];
            }
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> res = sol.combinationSum3(3, 7);
    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

