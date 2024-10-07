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
        return a[1] > b[1];
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return 1;
        // sort intervals by start time, then end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        // minheap with earliest end times at the top
        priority_queue<vector<int>, vector<vector<int>>, Compare> minh;
        minh.push(intervals[0]);
        int maxMR = 1;
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            vector<int> top = minh.top();
            while (!minh.empty() && top[1] <= interval[0]) { // while top of minh is a meeting that has already ended
                minh.pop();
                if (!minh.empty()) top = minh.top();
            }
            minh.push(interval);
            maxMR = max(maxMR, (int)minh.size());
        }
        return maxMR;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> intervals = {{0,10},{5,10},{0,30},{15,20}};
    cout << sol.minMeetingRooms(intervals) << "\n";

    intervals = {{7,10},{2,4}};
    cout << sol.minMeetingRooms(intervals) << "\n"; // 1

    intervals = {{7,10}};
    cout << sol.minMeetingRooms(intervals) << "\n"; // 1

    intervals = {{13,15},{1,13}};
    cout << sol.minMeetingRooms(intervals) << "\n"; // 1

    return 0;
}

