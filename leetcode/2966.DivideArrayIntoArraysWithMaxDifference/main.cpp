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
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int counter = 0;
        vector<int> cur;
        for (int i = 0; i < nums.size(); i++) {
            if (counter == 3) {
                if (cur[2] - cur[0] > k) {
                    return {};
                } else {
                    res.push_back(cur);
                    counter = 0;
                    cur.clear();
                }
            }
            cur.push_back(nums[i]);
            counter++;
        }
        if (cur[2] - cur[0] > k) {
            return {};
        } else {
            res.push_back(cur);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> res = sol.divideArray(nums, k);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    nums = {2,4,2,2,5,2};
    k = 2;
    res = sol.divideArray(nums, k);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

