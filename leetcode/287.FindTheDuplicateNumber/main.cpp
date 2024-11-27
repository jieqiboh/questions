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
    int findDuplicate(vector<int>& nums) {
        // Floyd's Algo
        int tortoise = nums[0];
        int hare = nums[0];

        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
        int steps = 1;
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            steps++;
        }
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,2,3,4,2};
    cout << sol.findDuplicate(nums) << "\n"; // 2

    nums = {3,1,3,4,2};
    cout << sol.findDuplicate(nums) << "\n"; // 3

    nums = {3,3,3,3};
    cout << sol.findDuplicate(nums) << "\n"; // 3

    nums = {3,3};
    cout << sol.findDuplicate(nums) << "\n"; // 3
    return 0;
}

