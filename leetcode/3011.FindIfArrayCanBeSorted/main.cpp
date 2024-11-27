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
    int numSetBits(int num) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += num & 1;
            num >>= 1;
        }
        return res;
    }

    bool canSortArray(vector<int>& nums) {
        // if thr exists a nbr > cur nbr, with a diff no of sb
        unordered_map<int,int> mx; // maps sb to max nbr
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int x = numSetBits(num);
            mx[x] = max(mx[x], num);

            for (pair<int,int> p : mx) {
                int sb = p.first;
                int val = p.second;
                if (sb == x) continue;
                if (val > num) return false;
            }
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {8,4,2,30,15};
    cout << sol.canSortArray(nums) << "\n"; // 1

    nums = {1,2,3,4,5};
    cout << sol.canSortArray(nums) << "\n"; // 1

    nums = {3,16,8,4,2};
    cout << sol.canSortArray(nums) << "\n"; // 0

    return 0;
}

