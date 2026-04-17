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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        // do some form of backtracking
        return backtrack(0, 0, total / 2, nums);
    }

    bool backtrack(int i, int cur, int exp, vector<int>& nums) {
        // idx - what we're considering
        if (cur == exp) {
            return true;
        }
        if (i > nums.size() - 1) {
            return false;
        }
        // explore paths where we use the num / dont use it
        bool tmp = backtrack(i+1, cur, exp, nums) || backtrack(i+1, cur + nums[i], exp, nums);
        return tmp;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,2,5};
    cout << sol.canPartition(nums);

    return 0;
}

