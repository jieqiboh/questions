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
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> prefSums;

        int cur = 0;
        prefSums.push_back(cur);
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            prefSums.push_back(cur);
        }

        unordered_map<int,int> idxMap; // maps rem to earliest encountered idx

        for (int i = 0; i < prefSums.size(); i++) {
            int rem = prefSums[i] % k;
            if (idxMap.find(rem) != idxMap.end()) {
                if (i - idxMap[rem] >= 2) return true;
                continue;
            } else {
                idxMap[rem] = i; // this is the earliest idx whr this rem was encountered
            }
        }

        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {23,2,4,6,6};
    int k = 7;
    cout << sol.checkSubarraySum(nums, k) << "\n"; // 1

    nums = {5,0,0,0};
    k = 3;
    cout << sol.checkSubarraySum(nums, k) << "\n"; // 1

    return 0;
}

