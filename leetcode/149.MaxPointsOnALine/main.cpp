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
    int maxPoints(vector<vector<int>>& points) {
        // for every point, compute the arc tangent with that point and the other points
        int totMax = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> angleFreq; // frequency of angles
            vector<int> coordI = points[i];
            int curMax = 0;
            for (int j = 0; j < points.size(); j++) {
                if (j != i) {
                    vector<int> coordJ = points[j];
                    double angle = atan2(coordI[1] - coordJ[1], coordI[0] - coordJ[0]);
                    angleFreq[angle]++;
                    curMax = max(curMax, angleFreq[angle]);
                }
            }
            totMax = max(totMax, curMax);
        }
        return totMax + 1; // include original point
    }
};

int main() {
    fast();
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    Solution sol;
    cout << sol.maxPoints(points) << "\n";

    return 0;
}

