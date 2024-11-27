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
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            int nextElem = (mid < nums.size() - 1) ? nums[mid + 1] : -1;
            int prevElem = (mid > 0) ? nums[mid - 1] : -1;
            if (mid % 2 == 0) { // even idx
                // if next elem is equal, search right
                // else if prev elem is equal, search left
                // else return mid
                if (nextElem == nums[mid]) {
                    l = mid + 1;
                } else if (prevElem == nums[mid]) {
                    r = mid - 1;
                } else {
                    return nums[mid];
                }
            } else { // idx is odd
                if (nextElem == nums[mid]) {
                    r = mid - 1;
                } else if (prevElem == nums[mid]) {
                    l = mid + 1;
                } else {
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,1,2,2,3,3,4,5,5};
    cout << sol.singleNonDuplicate(nums) << "\n"; // 4

    nums = {3,3,7,7,10,11,11};
    cout << sol.singleNonDuplicate(nums) << "\n"; // 10

    nums = {3};
    cout << sol.singleNonDuplicate(nums) << "\n"; // 3

    return 0;
}

