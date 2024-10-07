// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
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

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int res = nums[0];
        int total = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            total += nums[i];
            res = max(res, (int)ceil(total / (i + 1)));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,7,1,6};
    cout << sol.minimizeArrayValue(nums) << "\n"; // 5

    nums = {3,4,5};
    cout << sol.minimizeArrayValue(nums) << "\n"; // 4
    nums = {1,1,1};
    cout << sol.minimizeArrayValue(nums) << "\n"; // 1
    nums = {10,1};
    cout << sol.minimizeArrayValue(nums) << "\n"; // 10
    return 0;
}
