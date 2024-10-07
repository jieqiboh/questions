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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // keep a monotonically decreasing stack
        // every time we want to place a new element on top
        // must ensure that current top is greater than new element
        stack<int> s; // contains idxes of elements
        vector<int> res(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                res[i] = 0;
                s.push(i);
            } else {
                while (!s.empty() && temperatures[s.top()] <= temperatures[i]) { // find future day that is hotter
                    s.pop();
                }
                if (s.empty()) { // no future days are hotter
                    res[i] = 0;
                } else {
                    res[i] = s.top() - i;
                }
                s.push(i);
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> res = sol.dailyTemperatures(temperatures); // [1,1,4,2,1,1,0,0]
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    temperatures = {30,40,50,60};
    res = sol.dailyTemperatures(temperatures); // [1,1,1,0]
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    temperatures = {30,60,90};
    res = sol.dailyTemperatures(temperatures); // [1,1,0]
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

