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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        for (int i : nums) {
            dfs(i, nums, res);
        }
        return res;
    }

    void dfs(int start, vector<int>& nums, vector<vector<int>>& res) {
        unordered_set<int> visited;
        stack<vector<int>> s;

        s.push({start});
        visited.insert(start);
        while (!s.empty()) {
            vector<int> cur = s.top();
            s.pop();

            if (cur.size() == nums.size()) res.push_back(cur);

            for (int i : nums) {
                if (visited.find(i) == visited.end()) {
                    vector<int> newVec(cur.begin(), cur.end());
                    newVec.push_back(i);
                    s.push(newVec);
                    visited.insert(i);
                }
            }
        }

    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = sol.permute(nums);

    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

