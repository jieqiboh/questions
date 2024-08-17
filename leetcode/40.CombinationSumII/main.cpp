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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tempList;
        sort(candidates.begin(), candidates.end());

        backtrack(res, candidates, target, tempList, 0, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& tempList, int curSum, int j) {
        if (curSum == target) {
            res.push_back(tempList);
        } else {
            for (int i = j; i < candidates.size(); i++) {
                if (i > j && candidates[i] == candidates[i - 1]) continue;
                tempList.push_back(candidates[i]);
                curSum+=candidates[i];

                backtrack(res, candidates, target, tempList, curSum, i + 1);

                curSum-=candidates[i];
                tempList.pop_back();
            }
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5}; // 1 1 2 5 6 7 10
    int target = 8;
    vector<vector<int>> res = sol.combinationSum2(candidates, target);
    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

