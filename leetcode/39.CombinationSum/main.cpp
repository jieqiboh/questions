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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        for (int i = 0; i < candidates.size(); i++) {
            vector<int> newList = {candidates[i]};
            vector<int> newCandidates(candidates.begin() + i, candidates.end());
            dfs(newList, candidates[i], newCandidates, target, res);
        }
        return res;
    }

    void dfs(vector<int>& curList, int curSum, vector<int>& candidates, int target, vector<vector<int>>& res) {
        if (curSum == target) {
            res.push_back(curList);
        } else if (curSum > target) {
            return;
        } else {
            for (int i = 0; i < candidates.size(); i++) {
                vector<int> newList(curList.begin(), curList.end());
                newList.push_back(candidates[i]);
                int newSum = curSum + candidates[i];
                vector<int> newCandidates(candidates.begin() + i, candidates.end());
                dfs(newList, newSum, newCandidates, target, res);
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = sol.combinationSum(candidates, target);

    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

