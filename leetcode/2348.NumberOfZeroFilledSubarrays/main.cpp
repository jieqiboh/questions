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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;

        long long curSz = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                curSz++;
            } else {
                res += (curSz * (curSz + 1) / 2);
                curSz = 0;
            }
        }
        res += (curSz * (curSz + 1) / 2);

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {0,0,1,0,0};
    cout << sol.zeroFilledSubarray(nums) << "\n"; // 6

    return 0;
}

