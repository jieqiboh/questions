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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        // min sum at the top
        priority_queue<pair<int,int>> pq; // contains sum and idx of num from nums2

        for (int i : nums1) {
            pq.push({i + nums2[0], 0});
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;
    vector<vector<int>> res = sol.kSmallestPairs(nums1, nums2, k); // [[1,2],[1,4],[1,6]]
    for (auto& v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    nums1 = {1,1,2};
    nums2 = {1,2,3};
    k = 2;
    res = sol.kSmallestPairs(nums1, nums2, k); // [[1,1],[1,1]]
    for (auto& v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }


    return 0;
}

