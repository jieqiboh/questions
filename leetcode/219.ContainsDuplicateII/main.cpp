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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;

        unordered_set<int> seen; // contains the numbers in the range k
        deque<int> seen_deque(0); // used to get order of numbers inserted

        // initialise the hashset
        for (int i = 0; i <= k && i < nums.size(); i++) {
            if (seen.find(nums[i]) == seen.end()) { // number not seen before
                seen.insert(nums[i]);
                seen_deque.push_back(nums[i]);
            } else {
                return true;
            }
        }

        // continue moving the sliding window
        for (int i = k + 1; i < nums.size(); i++) {
            int front = seen_deque.front();
            seen.erase(front);
            seen_deque.pop_front();

            if (seen.find(nums[i]) == seen.end()) { // number not seen before
                seen.insert(nums[i]);
                seen_deque.push_back(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {1,2,3,1};
    int k = 3;

    cout << sol.containsNearbyDuplicate(nums, k) << "\n"; // 1

    nums = {1,0,1,1};
    k = 1;
    cout << sol.containsNearbyDuplicate(nums, k) << "\n"; // 1

    nums = {1,2,3,1,2,3};
    k = 2;
    cout << sol.containsNearbyDuplicate(nums, k) << "\n"; // 0
    return 0;
}

