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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[0] > b[0]; // minheap, order by first elem
    }
};

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> n1n2;
        for (int i = 0; i < nums1.size(); i++) {
            n1n2.push_back({nums1[i],nums2[i]});
        }
        sort(n1n2.begin(), n1n2.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] > b[1];
        });

        long long res = INT32_MIN;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq; // order by value
        long long minMult = INT32_MAX;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            vector<int> cur = n1n2[i];
            pq.push(cur);
            sum += cur[0];
            minMult = cur[1];
        }

        res = max(res, (long long)minMult * (long long)sum);
        for (int i = k; i < n1n2.size(); i++) {
            vector<int> top = pq.top();
            vector<int> cur = n1n2[i];
            pq.pop();
            pq.push(cur);
            sum -= top[0];
            sum += cur[0];
            minMult = cur[1];
            res = max(res, (long long)minMult * (long long)sum);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
//    vector<int> nums1 = {1,3,3,2};
//    vector<int> nums2 = {2,1,3,4};
//    int k = 3;
//    long long res = sol.maxScore(nums1, nums2, k);
//    cout << res << "\n"; // 12
//    nums1 = {1,3,3,2,1};
//    nums2 = {2,1,3,4,1};
//    k = 3;
//    res = sol.maxScore(nums1, nums2, k);
//    cout << res << "\n"; // 12

    vector<int> nums1 = {4,2,3,1,1};
    vector<int> nums2 = {7,5,10,9,6};
    int k = 1;
    int res = sol.maxScore(nums1, nums2, k);
    cout << res << "\n"; // 30
    return 0;
}

