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
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times; // mins elapsed since 00:00
        for (string s : timePoints) {
            string hour = s.substr(0, s.find(":"));
            string minute = s.substr(s.find(":") + 1);
            times.push_back({stoi(hour) * 60 + stoi(minute)});
        }
        sort(times.begin(), times.end());
        int minDiff = INT32_MAX;
        for (int i = 0; i < times.size() - 1; i++) {
            int diff = times[i+1] - times[i];
            if (diff < minDiff) minDiff = diff;
        }
        int lastFirstDiff = 24*60 - times[times.size() - 1] + times[0];
        minDiff = min(minDiff, lastFirstDiff);
        return minDiff;
    }
};

int main() {
    fast();
    Solution sol;
    vector<string> timePoints = {"00:00","23:59","00:00"};
    cout << sol.findMinDifference(timePoints) << "\n"; // 0

    timePoints = {"23:59","00:00"};
    cout << sol.findMinDifference(timePoints) << "\n"; // 1
    return 0;
}

