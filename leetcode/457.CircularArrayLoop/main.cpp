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
    int nxt(vector<int>& nums, int cur) {
        return (cur + nums[cur] + nums.size()) % nums.size();
    }
    bool circularArrayLoop(vector<int>& nums) {
        // slow pter, fast pter
        // next idx = (curidx + jmpval + sz) % sz

        int n = nums.size();
        int slow = 0;
        int fast = 0;
        // all nodes must be same sign

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue; // skip

            int sign = nums[slow] > 0;
            slow = i;
            fast = nxt(nums, i);
            while ((nums[slow] > 0) == sign && (nums[fast] > 0) == sign && (nums[nxt(nums, fast)] > 0) == sign) { // if not unidir, terminate
                if (slow == fast) { // unidir and equal
                    if (slow == nxt(nums, slow)) break; // single loop not valid
                    return true; // same sign, not single loop
                }
                fast = nxt(nums, nxt(nums, fast));
                slow = nxt(nums, slow);
            }
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,-1,1,2,2};
    cout << sol.circularArrayLoop(nums) << "\n"; // 1

    nums = {-1,-2,-3,-4,-5,6};
    cout << sol.circularArrayLoop(nums) << "\n"; // 0

    nums = {1,-1,5,1,4};
    cout << sol.circularArrayLoop(nums) << "\n"; // 1

    nums = {1,-1};
    cout << sol.circularArrayLoop(nums) << "\n"; // 0

    nums = {1};
    cout << sol.circularArrayLoop(nums) << "\n"; // 0

    nums = {-2,1,-1,-2,-2};
    cout << sol.circularArrayLoop(nums) << "\n"; // 0
    return 0;
}

