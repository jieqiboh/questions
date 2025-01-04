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
    int maxTwoEvents(vector<vector<int>>& events) {
        if (events.size() == 1) return events[0][2];
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // minheap, end time, val

        sort(events.begin(), events.end()); // sort by start

        int res = 0;
        int maxVal = 0; // represents max value out of all confirmed non-overlapping events

        for (int i = 0; i < events.size(); i++) {
            vector<int> e = events[i];
            while (!pq.empty()) { // used to find new maxVal
                vector<int> cur = pq.top();
                pq.pop();

                if (cur[0] >= e[0]) { // overlap
                    pq.push(cur);
                    break;
                } else {
                    maxVal = max(maxVal, cur[1]);
                }
            }

            res = max(res, e[2] + maxVal);
            pq.push({e[1],e[2]}); // add the current event to the pq
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    cout << sol.maxTwoEvents(events) << "\n"; // 4

    events = {{1,3,2},{4,5,2},{1,5,5}};
    cout << sol.maxTwoEvents(events) << "\n"; // 5

    events = {{1,5,3},{1,5,1},{6,6,5}};
    cout << sol.maxTwoEvents(events) << "\n"; // 8
    
    events = {{66,97,90},{98,98,68},{38,49,63},{91,100,42},{92,100,22},{1,77,50},{64,72,97}};
    cout << sol.maxTwoEvents(events) << "\n"; // 165

    events = {{22,44,9},{93,96,48},{56,90,3},{80,92,45},{63,73,69},{73,96,33},{11,23,84},{59,72,29},{89,100,46}};
    cout << sol.maxTwoEvents(events) << "\n"; // 153
    return 0;
}

