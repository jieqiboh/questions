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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tempList;
        sort(nums.begin(), nums.end());
        vector<int> used(nums.size(), false);
        backtrack(res, tempList, nums, used);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& tempList, vector<int>& nums, vector<int>& used) {
        if (tempList.size() == nums.size()) {
            res.push_back(tempList);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (used[i] || i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
                used[i] = true;
                tempList.push_back(nums[i]);
                backtrack(res, tempList, nums, used);
                used[i] = false;
                tempList.pop_back();
            }
        }
    }
};

int main() {
    fast();

    return 0;
}

