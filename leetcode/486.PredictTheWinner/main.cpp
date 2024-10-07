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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1) >= 0;
    }
    int dfs(vector<int>& nums, int i, int j) {
        if (i > j) return 0;
        return max(nums[i] - dfs(nums, i+1, j), nums[j] - dfs(nums, i, j-1));
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,5,233,7};
    cout << sol.predictTheWinner(nums) << "\n"; // 1

    nums = {1,5,2};
    cout << sol.predictTheWinner(nums) << "\n"; // 0

    return 0;
}

