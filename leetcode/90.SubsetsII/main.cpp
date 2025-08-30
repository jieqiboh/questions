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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmpList;
        sort(nums.begin(), nums.end());
        backtrack(res, nums, tmpList, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmpList, int start) {
        res.push_back(tmpList);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            tmpList.push_back(nums[i]);
            backtrack(res, nums, tmpList, i + 1);
            tmpList.pop_back();
        }
    }
};

int main() {
    fast();

    return 0;
}

