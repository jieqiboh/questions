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
    void rotate(vector<int>& nums, int k) {
        int steps = k % nums.size(); // actual number of steps to take

        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int new_idx = (i + steps) % nums.size();
            res[new_idx] = nums[i];
        }
        nums = res;
    }
};

int main() {
    fast();

//    vector<int> nums = {1,2,3,4,5,6,7};
//    int k = 3;
    vector<int> nums2 = {-1,-100,3,99};
    int l = 2;

    Solution sol;
//    sol.rotate(nums, k);
    sol.rotate(nums2, l);




    return 0;
}

