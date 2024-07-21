#include <cinttypes>
#include <iostream>
#include <iterator>
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

int searchFirst(vector<int>& nums, int target) {
    int ans = -1;

    int l = 0; int r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            ans = mid;
            r = mid - 1; // continue searching the right side for even later instances
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int searchLast(vector<int>& nums, int target) {
    int ans = -1;

    int l = 0; int r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            ans = mid;
            l = mid + 1; // continue searching the left side for even earlier instances
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_idx = searchFirst(nums, target);
        int last_idx = searchLast(nums, target);

        return {first_idx, last_idx};
    }
};

int main() {
    fast();

    Solution sol;

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> res;

    res = sol.searchRange(nums, target); 

    cout << res[0] << " " << res[1] << "\n";

    target = 6;

    res = sol.searchRange(nums, target); 

    cout << res[0] << " " << res[1] << "\n";

    nums = {};
    target = 0;
    res = sol.searchRange(nums, target); 

    cout << res[0] << " " << res[1] << "\n";


    return 0;
}

