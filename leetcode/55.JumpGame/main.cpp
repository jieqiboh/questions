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
    bool canJump(vector<int>& nums) {
        // take the max of nums[i] - 1 and nums[i+1]

        for (int i = 0; i < nums.size() - 1; i ++) {
            int max = std::max(nums[i] - 1, nums[i+1]);
//            cout << max << " ";
            if (max == 0) {
                return false;
            }
            nums[i+1] = max;
        }
        return true;
    }
};

int main() {
    fast();

    vector<int> nums = {2,3,1,1,4};

    Solution sol;
    bool isJumpable = sol.canJump(nums);

    cout << "\n" << isJumpable;

    return 0;
}

