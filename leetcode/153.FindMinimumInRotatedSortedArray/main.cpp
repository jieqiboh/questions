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
    int findMin(vector<int>& nums) {
        // Draw a diagram visualising the values
        // We want to find the first element in the array with the previous elem greater than itself
        // We will use the nums[0] for comparing and doing binary search
        int first = nums[0];

        int l = 0;
        int r = nums.size() - 1;

        if (first <= nums[nums.size() - 1]) {
            return nums[0];
        }
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < first) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main() {
    fast();

    Solution sol;

    vector<int> nums = {3,4,5,1,2}; 
    cout << sol.findMin(nums) << "\n"; // 1
    nums = {0,1,2,3};
    cout << sol.findMin(nums) << "\n"; // 0
    nums = {3,1,2};
    cout << sol.findMin(nums) << "\n"; // 1
    nums = {1,2,3,0};
    cout << sol.findMin(nums) << "\n"; // 0
    nums = {4,5,6,7,0,1,2};
    cout << sol.findMin(nums) << "\n"; // 0
    nums = {11,13,15,17};
    cout << sol.findMin(nums) << "\n"; // 11

    return 0;
}

