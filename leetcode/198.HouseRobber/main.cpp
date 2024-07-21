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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int rob(vector<int>& nums) {
       if (nums.size() == 1) {
           return nums[0];
       }

       vector<int> res(nums.size());
       for (int i = 0; i < nums.size(); i++) {
           int l = (i - 2 >= 0) ? nums[i] + res[i - 2] : nums[i];
           int r = (i - 1 >= 0) ? res[i - 1] : 0;
           res[i] = max(l, r);
       }
       return res[nums.size() - 1];
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << sol.rob(nums) << "\n"; // 4
    nums = {5,2,3,5};
    cout << sol.rob(nums) << "\n"; // 10

    return 0;
}

