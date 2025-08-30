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
    int maxAscendingSum(vector<int>& nums) {
        int curSum = nums[0];
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { // increasing
                curSum += nums[i];
            } else {
                res = max(res, curSum);
                curSum = nums[i];
            }
        }
        res = max(res, curSum);
        return res;
    }
};

int main() {
    fast();

    return 0;
}

