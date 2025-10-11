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
    int numberOfPairs(vector<vector<int>>& points) {
        // sort by ascending x, then decreasing y

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
             });

        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            vector<int> A = points[i];
            int minY = INT_MIN;

            for (int j = i + 1; j < points.size(); j++) {
                vector<int> B = points[j];

                if (B[1] > minY && A[1] >= B[1]) {
                    res++;
                    minY = B[1];
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout << sol.numberOfPairs(points) << "\n"; // 0



    return 0;
}

