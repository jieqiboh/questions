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
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (compute(dist, hour, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    bool compute(vector<int>& dist, double hour, int speed) {
        // computes if it is possible to travel to office within hours given speed
        double curHour = 0;
        for (int i = 0; i < dist.size(); i++) {
            int curDist = dist[i];
            double timeTaken = curDist / double(speed);
            if (i == dist.size() - 1) {
                curHour += timeTaken; // no need to rount up at the end
            } else {
                curHour += ceil(timeTaken);
            }
        }
        return curHour <= hour;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> dist = {1,3,2};
    double hour = 2.7;
    cout << sol.minSpeedOnTime(dist, hour) << "\n"; // 3

    dist = {1,3,2};
    hour = 6;
    cout << sol.minSpeedOnTime(dist, hour) << "\n"; // 1

    dist = {1,3,2};
    hour = 1.9;
    cout << sol.minSpeedOnTime(dist, hour) << "\n"; // -1
    return 0;
}

