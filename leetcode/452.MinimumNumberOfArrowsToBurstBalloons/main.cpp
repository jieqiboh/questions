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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct sort_pred {
    bool operator()(const std::vector<int> &left, const std::vector<int> &right) {
        if (left[0] == right[0]) {
            return left[1] < right[1]; // Compare by the second element if the first ones are equal
        }
        return left[0] < right[0]; // Otherwise, compare by the first element
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end(), sort_pred());

        vector<int> interval = points[0]; // at the start of every loop, this is the current interval being considered
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= interval[1]) { // overlap
                interval[0] = max(interval[0], points[i][0]);
                interval[1] = min(interval[1], points[i][1]);
            } else {
                res++;
                interval = points[i];
            }
        }
        res += 1;
        return res;
    }
};
int main() {
    fast();
    
    Solution sol;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};

    cout << sol.findMinArrowShots(points) << "\n";

    points = {{1,2},{3,4},{5,6},{7,8}};
    cout << sol.findMinArrowShots(points) << "\n";
    return 0;
}

