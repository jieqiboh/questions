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
    int jump(vector<int>& nums) {
        vector<int> min_steps(nums.size());

        min_steps[0] = 0; // always start with 0

        for (int i = 1; i < nums.size(); i++) {
            // at each index, check from [1,idx) for idxes that can reach it
            // then take the idx with the min steps required to reach it
            int min_step = INT32_MAX;
            for (int j = 0; j < i; j++) {
                if ((j + nums[j] >= i) && (min_steps[j] < min_step)) {
                    min_step = min_steps[j] + 1;
                }
            }
            min_steps[i] = min_step;
        }
        return min_steps[nums.size()-1];
    }
};

int main() {
    fast();

    vector<int> nums = {2,3,1,1,4};

    Solution sol;
    int min_step = sol.jump(nums);
    cout << min_step;

    return 0;
}

