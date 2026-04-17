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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        // merge all the intervals and find gaps
        vector<vector<int>> v; // contains flattened schedule
        for (vector<Interval>& vi : schedule) {
            for (Interval& i : vi) {
                v.push_back({i.start, i.end});
            }
        }

        sort(v.begin(), v.end());
        // merge intervals
        vector<vector<int>> merged;
        int curStart = v[0][0];
        int curEnd = v[0][1]; // current endpoint
        for (auto& i : v) {
            if (curEnd < i[0]) {
                // new interval
                merged.push_back({curStart, curEnd});
                curStart = i[0];
                curEnd = i[1];
            } else {
                curEnd = max(curEnd, i[1]);
            }
        }
        merged.push_back({curStart, curEnd});

        // find gaps
        vector<Interval> res;
        for (int i = 0; i < merged.size() - 1; i++) {
            res.push_back({merged[i][1], merged[i+1][0]});
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<Interval>> schedule = {{{1,2},{5,6}},{{1,3}},{{4,10}}};
    vector<Interval> res = sol.employeeFreeTime(schedule);
    for (Interval i : res) {
        cout << i.start << " " << i.end << "\n";
    }
    return 0;
}

