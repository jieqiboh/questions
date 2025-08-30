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
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balls;
//        vector<int> balls(limit + 1, 0);

        unordered_map<int,int> m; // maps each color to its freq

        vector<int> res;
        for (vector<int> vi : queries) {
            int idx = vi[0];
            int color = vi[1];

            int curColor = 0;
            if (balls.find(idx) != balls.end()) {
                curColor = balls[idx];
            }
            balls[idx] = color;

            if (curColor != 0) { // ball is colored
                m[curColor]--;
                if (m[curColor] == 0) {
                    m.erase(curColor);
                }
            }

            m[color]++;
            res.push_back(m.size());
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int limit = 4;
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};
    vector<int> res = sol.queryResults(limit, queries);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n"; // 1 2 2 3

    limit = 4;
    queries = {{1,4},{2,5},{2,3},{1,3}};
    res = sol.queryResults(limit, queries);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n"; // 1 2 2 1

    return 0;
}

