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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tempList = {};
        backtrack(res, tempList, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& tempList, vector<int>& nums, int start) {
        res.push_back(tempList);
        for (int i = start; i < nums.size(); i++) {
            tempList.push_back(nums[i]);
            backtrack(res, tempList, nums, i);
            tempList.pop_back();
        }
    }
};

int main() {
    fast();

    return 0;
}

