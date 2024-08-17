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
        vector<int> tempList;
        unordered_set<int> tempSet; // contains the integers in tempList
        backtrack(res, tempList, tempSet, nums);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int> tempList, unordered_set<int>& tempSet, vector<int>& nums) {
        if (tempList.size() == nums.size()) {
            res.push_back(tempList);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (tempSet.find(nums[i]) == tempSet.end()) {
                    tempList.push_back(nums[i]);
                    tempSet.insert(nums[i]);
                    backtrack(res, tempList, tempSet, nums);
                    tempSet.erase(nums[i]);
                    tempList.pop_back();
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

