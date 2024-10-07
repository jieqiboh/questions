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

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<>> l;
        priority_queue<int, vector<int>, greater<>> r;
        int c = candidates;
        int lidx = 0; int ridx = costs.size() - 1;
        while (lidx <= ridx && candidates > 0) {
            l.push(costs[lidx++]);
            if (lidx <= ridx) r.push(costs[ridx--]);
            candidates--;
        }

        long long cost = 0;
        for (int i = 0; i < k; i++) {
            if (l.empty() || (!r.empty() && r.top() < l.top())) {
                // Choose from the right queue if it's smaller or left queue is empty
                cost += r.top();
                r.pop();
                if (lidx <= ridx) r.push(costs[ridx--]);
            } else {
                // Otherwise, choose from the left queue
                cost += l.top();
                l.pop();
                if (lidx <= ridx) l.push(costs[lidx++]);
            }
        }
        return cost;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> costs = {17,12,10,2,7,2,11,20,8};
    int k = 3;
    int candidates = 4;
    cout << sol.totalCost(costs, k, candidates) << "\n"; // 11

    costs = {1,2,4,1};
    k = 3;
    candidates = 3;
    cout << sol.totalCost(costs, k, candidates) << "\n"; // 4

    costs = {3,2,7,7,1,2};
    k = 5;
    candidates = 2;
    cout << sol.totalCost(costs, k, candidates) << "\n"; // 4

    return 0;
}

