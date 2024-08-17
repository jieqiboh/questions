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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        int kIndex = nums.size() - k;
        while (true) {
            int pivot_index = rand() % (r - l + 1) + l; // Random pivot
            int idx = partition(nums, l, r, pivot_index);
            if (idx == kIndex) {
                return nums[idx];
            } else if (idx > kIndex) {
                r = idx - 1;
            } else { // idx < kIndex
                l = idx + 1;
            }
        }
    }

    int partition(std::vector<int>& arr, int l, int r, int pivot_index) {
        std::swap(arr[pivot_index], arr[r]); // Move pivot to the end
        int x = arr[r]; // Pivot value
        int i = l;
        for (int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                std::swap(arr[i], arr[j]);
                i++;
            }
        }
        std::swap(arr[i], arr[r]); // Move pivot to its final place
        return i;
    }
};


int main() {
    fast();
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    cout << sol.findKthLargest(nums, 2) << "\n"; // 5

    nums = {3,2,3,1,2,4,5,5,6};
    cout << sol.findKthLargest(nums, 4) << "\n"; // 4

    return 0;
}

