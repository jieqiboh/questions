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
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int cur = 0; // [i,j)
        int i = 0;
        set<int> s;

        for (int j = 0; j < nums.size(); j++) {
            // nums[j] is the element we are going to newly insert
            while (s.find(nums[j]) != s.end()) {
                cur -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            s.insert(nums[j]);
            cur += nums[j];
            res = max(res, cur);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {8,8,8};
    cout << sol.maximumUniqueSubarray(nums) << "\n"; // 8

    nums = {8,7,8};
    cout << sol.maximumUniqueSubarray(nums) << "\n"; // 15

    nums = {4,1,2,5,4};
    cout << sol.maximumUniqueSubarray(nums) << "\n"; // 12
    return 0;
}

