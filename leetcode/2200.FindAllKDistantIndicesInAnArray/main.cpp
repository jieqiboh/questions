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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                for (int j = i - k; j <= i + k; j++) {
                    if (j < 0 || j >= nums.size()) continue;
                    res.insert(j);
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {3,4,9,1,3,9,5};
    int k = 1;
    int key = 9;
    vector<int> res = sol.findKDistantIndices(nums, key, k);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    nums = {2,2,2,2,2};
    k = 2;
    key = 2;
    res = sol.findKDistantIndices(nums, key, k);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}

