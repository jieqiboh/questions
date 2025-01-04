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
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> maxRch(nums.size(), -1);

        int i = 0;
        int j = 1;
        int k = 0;
        while (j < nums.size()) {
            if (nums[i] % 2 == nums[j] % 2) {
                for (; k < j; k++) {
                    maxRch[k] = i;
                }
            }
            j++;
            i++;
        }
        for (; k < j; k++) {
            maxRch[k] = i;
        }
//        for (int x : maxRch) {
//            cout << x << " ";
//        }
//        cout << "\n";
        vector<bool> res;
        for (vector<int> q : queries) {
            int start = q[0];
            int end = q[1];
            res.push_back(maxRch[start] == maxRch[end]);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> queries = {{0,4}};
    vector<int> nums = {3,4,1,2,6};
    vector<bool> res = sol.isArraySpecial(nums, queries);
    for (bool b : res) {
        cout << b << " ";
    }
    cout << "\n";

    queries = {{0,2},{2,3}};
    nums = {4,3,1,6};
    res = sol.isArraySpecial(nums, queries);
    for (bool b : res) {
        cout << b << " ";
    }
    cout << "\n";
    return 0;
}

