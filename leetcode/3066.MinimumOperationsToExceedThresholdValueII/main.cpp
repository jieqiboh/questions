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
#include <cstdio>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        ll res = 0;
        while (pq.size() >= 2) {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();

            if (x >= k) break;

            // need to perform an operation
            pq.push(min(x, y) * 2 + max(x, y));
            res++;
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    cout << sol.minOperations(nums, k) << "\n"; // 2

    return 0;
}

