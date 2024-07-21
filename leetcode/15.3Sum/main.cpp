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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = i + 1;
        int k = nums.size() - 1;

        set<vector<int>> ans;

        while (i < nums.size() - 3) {
            while (j < k) {
//                int num_i = nums[i];
//                int num_j = nums[j];
//                int num_k = nums[k];
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.insert({nums[i], nums[j], nums[k]});
                    break;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
            }
            i++; // need to increment i
            j = i + 1;
            k = nums.size() - 1;
        }

        vector<vector<int>> res;
        for (auto& x : ans) {
            res.push_back(x);
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = sol.threeSum(nums);

    for (vector<int> x : ans) {
        cout << x[0] << " " << x[1] << " " << x[2] << "\n";
    }

    return 0;
}

