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
    int lengthOfLIS(vector<int>& nums, int i = 0, int prev = INT32_MIN) {
        // i is the current idx being considered
        unordered_map<int,int> cache; // maps idxes to lengthOfLIS
        if(i == nums.size()) return 0;
        // prev is the prev max of the subsequence
        // take max between: don't take current element
        return dfs(nums, 0, prev, cache);
    }
    int dfs(vector<int>& nums, int i, int prev, unordered_map<int,int>& cache) {
        if (cache.find(i) != cache.end()) return cache[i];
        if (i == nums.size()) {
            return 0;
        } else {
            int take = (nums[i] > prev) + dfs(nums, i + 1, max(nums[i], prev), cache);
            int noTake = dfs(nums, i + 1, prev, cache);
            int res = max(take, noTake);
            cache[i] = res;
            return res;
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {1,2,4,3};
    cout << sol.lengthOfLIS(nums) << "\n";

    return 0;
}

