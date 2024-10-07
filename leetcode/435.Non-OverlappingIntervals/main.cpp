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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by end time
        // if overlap occurs, take interval ending earliest
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int res = 0;
        int i = 0; // cur interval
        int j = 1; // nxt interval w/o overlap
        // compare i and j. if no overlap, set i to j, otherwise shift j until interval w/o overlap found
        while (i < intervals.size() && j < intervals.size()) {
            vector<int> cur = intervals[i];
            vector<int> nxt = intervals[j];
            if (cur[1] > nxt[0]) { // overlap
                j++; // ignore nxt interval
                res++; // 1 interval removed
            } else { // no overlap
                i = j;
                j++;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n"; // 1

    intervals = {{1,2},{1,2},{1,2}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n"; // 2

    intervals = {{1,2},{2,3}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n"; // 0

    intervals = {{1,2},{1,3},{1,4}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n"; // 2

    return 0;
}

