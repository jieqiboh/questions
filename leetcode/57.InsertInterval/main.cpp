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

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) { // no overlap, new before i
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++) {
                    res.push_back(intervals[j]);
                }
                return res;
            } else if (newInterval[0] > intervals[i][1]) { // no overlap, i before new
                res.push_back(intervals[i]);
            } else { // overlapping
                newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> res = sol.insert(intervals, newInterval);

    for (auto& x : res) {
        cout << x[0] << " " << x[1] << "\n";
    }
    cout << "\n";
    
    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval = {4,8};

    res = sol.insert(intervals, newInterval);

    for (auto& x : res) {
        cout << x[0] << " " << x[1] << "\n";
    }
    cout << "\n";

    intervals = {};
    newInterval = {4,8};

    res = sol.insert(intervals, newInterval);

    for (auto& x : res) {
        cout << x[0] << " " << x[1] << "\n";
    }
    return 0;
}

