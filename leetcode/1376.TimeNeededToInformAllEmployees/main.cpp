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
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(manager.size(), vector<int>()); // maps idx to subordinates
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            g[manager[i]].push_back(i);
        }
        int maxTime = 0;

        queue<pair<int,int>> q; // time, cur
        q.push({0,headID});
        while (!q.empty()) {
            pair<int,int> p = q.front();
            int cur = p.second;
            int time = p.first;
            maxTime = max(maxTime, time);
            q.pop();

            for (int sub : g[cur]) {
                q.push({time + informTime[cur], sub});
            }
        }
        return maxTime;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 6;
    int headID = 2;
    vector<int> manager = {2,2,-1,2,2,2};
    vector<int> informTime = {0,0,1,0,0,0};
    cout << sol.numOfMinutes(n, headID, manager, informTime) << "\n"; // 1

    n = 1;
    headID = 0;
    manager = {-1};
    informTime = {0};
    cout << sol.numOfMinutes(n, headID, manager, informTime) << "\n"; // 0

    return 0;
}

