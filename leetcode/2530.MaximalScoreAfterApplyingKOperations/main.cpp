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
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll> pq; // maxheap
        for (int n : nums) {
            pq.push(n);
        }
        ll score = 0;
        while (k--) {
            double top = pq.top();
            score += pq.top();
            pq.pop();
            pq.push(ceil(top / (double)3));
        }
        return score;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {10,10,10,10,10};
    int k = 5;
    cout << sol.maxKelements(nums, k) << "\n"; // 50

    nums = {1,10,3,3,3};
    k = 3;
    cout << sol.maxKelements(nums, k) << "\n"; //17
    return 0;
}

