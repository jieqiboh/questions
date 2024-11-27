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
    int minGroups(vector<vector<int>>& intervals) {
        // line sweep algo
        // overlap if interval
        vector<int> start;
        vector<int> end;
        sort(intervals.begin(), intervals.end()); // sort by start
        for (int i = 0; i < intervals.size(); i++) {
            start.push_back(intervals[i][0]);
        }
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];  // Compare by the second element
        }); // sort by end
        for (int i = 0; i < intervals.size(); i++) {
            end.push_back(intervals[i][1]);
        }

        int i = 0; int j = 0;
        int cnt = 0;
        int maxSz = 0;
        while (i < intervals.size() && j < intervals.size()) {
            if (start[i] <= end[j]) {
                i++;
                cnt++;
            } else { // end < start
                j++;
                cnt--;
            }
            maxSz = max(maxSz, cnt);
        }
        return maxSz;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> intervals = {{5,10},{6,8},{1,5},{2,3},{1,10}};
    cout << sol.minGroups(intervals) << "\n"; // 3

    intervals = {{1,3},{5,6},{8,10},{11,13}};
    cout << sol.minGroups(intervals) << "\n"; // 1

    intervals = {{1,3}};
    cout << sol.minGroups(intervals) << "\n"; // 1
    return 0;
}

