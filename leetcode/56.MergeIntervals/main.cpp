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

// Custom comparator for sorting
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sort_pred());

        vector<vector<int>> res;
        // at the start of every loop, interval denotes the current considered interval
        vector<int> interval = intervals[0];

        // res contains
        // intervals[l,r] is a valid interval at the start of every loop
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= interval[1]) { // part of the interval
                interval[1] = max(intervals[i][1], interval[1]);
            } else { // not part of the interval
                res.push_back(interval);
                interval = intervals[i];
            }
        }
        res.push_back(interval);

        return res;
    }
};

int main() {
    fast();

    vector<string> arr = {"apple", "banana", "cherry", "date"};
    // Sort in reverse lexicographical order
    sort(arr.begin(), arr.end(), greater<string>());

    Solution sol;
    vector<vector<int>> intervals = {{1,3},{15,18},{8,10},{2,6}};

    vector<vector<int>> res = sol.merge(intervals);

    for (auto x : res) {
        cout << x[0] << " " << x[1] << "\n";
    }
    cout << "\n";

    intervals = {{1,3},{2,6}};

    res = sol.merge(intervals);

    for (auto x : res) {
        cout << x[0] << " " << x[1] << "\n";
    }
    cout << "\n";

    intervals = {{1,3}};

    res = sol.merge(intervals);

    for (auto x : res) {
        cout << x[0] << " " << x[1] << "\n";
    }
    cout << "\n";
    
    intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    res = sol.merge(intervals);

    for (auto x : res) {
        cout << x[0] << " " << x[1] << "\n";
    }
    cout << "\n";

    return 0;
}

