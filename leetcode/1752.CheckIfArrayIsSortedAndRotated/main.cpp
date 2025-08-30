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
    bool check(vector<int>& nums) {
        int numPeaks = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                numPeaks++;
            }
        }
        if (nums[nums.size() - 1] > nums[0]) numPeaks++;
        return numPeaks <= 1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    cout << sol.check(nums) << "\n"; // 1

    nums = {2,1,3,4};
    cout << sol.check(nums) << "\n"; // 0

    nums = {1,2,3};
    cout << sol.check(nums) << "\n"; // 1

    nums = {1,1,1};
    cout << sol.check(nums) << "\n"; // 1
    return 0;
}

