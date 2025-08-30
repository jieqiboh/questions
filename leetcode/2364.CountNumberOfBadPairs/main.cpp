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
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<int,int> m; // maps nums[i] - i to its freq
        for (int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - i;

            res += i - m[diff]; // get the number of

            m[nums[i] - i]++;
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {4,1,3,3};
    cout << sol.countBadPairs(nums) << "\n";

    return 0;
}

