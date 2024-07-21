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

int findMiddle(vector<int>& nums) { // used for arrays that have been rotated
    int l = 0;
    int r = nums.size() - 1;

    int f = nums[0]; // first element

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= f) { // LHS of rotation
            if (nums[mid + 1] < f) {
                return mid + 1;
            } 
            l = mid + 1;
        } else {
            if (nums[mid - 1] >= f) {
                return mid;
            }
            r = mid - 1;
        }
    }
    return -1;
}

int binSearch(vector<int>& nums, int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // edge cases: arrays of size 1

        if (nums[0] <= nums[nums.size() - 1]) {
            return binSearch(nums, 0, nums.size() - 1, target);
        } else {
            int min_idx = findMiddle(nums);
            if (target >= nums[0]) {
                return binSearch(nums, 0, min_idx - 1, target);
            } else {
                return binSearch(nums, min_idx, nums.size() - 1, target);
            }
        }
        
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << sol.search(nums, target) << "\n";

    nums = {4,5,6,7,0,1,2};
    target = 3;

    cout << sol.search(nums, target) << "\n";

    nums = {1};
    target = 0;

    cout << sol.search(nums, target) << "\n";

    return 0;
}

