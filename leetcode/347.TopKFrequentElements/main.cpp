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
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for (pair<int,int> p : m) {
            pq.push(p);
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = sol.topKFrequent(nums, k);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

