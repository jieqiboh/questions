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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int j = 0; j < k; j++) {
            int minIdx = -1;
            int minVal = INT32_MAX;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < minVal) {
                    minIdx = i;
                    minVal = nums[i];
                }
            }
            nums[minIdx] = multiplier * nums[minIdx];
        }
        return nums;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {2,1,3,5,6};
    int k = 5;
    int multiplier = 2;
    vector<int> res = sol.getFinalState(nums, k, multiplier);
    for (int x : res) {
        cout << x << " "; // [8,4,6,5,6]
    }
    cout << "\n";

    return 0;
}

