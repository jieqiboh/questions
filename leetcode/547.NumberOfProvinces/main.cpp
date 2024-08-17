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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // construct an adjList from isConnected
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }
        int res = 0;

        stack<int> s;
        unordered_set<int> visited;

        while (visited.size() != isConnected.size()) {
            // get the next unvisited node
            for (int i = 0; i < isConnected.size(); i++) {
                if (visited.find(i) == visited.end()) {
                    s.push(i);
                    break;
                }
            }
            res++; // new connected component

            while (!s.empty()) {
                int curNode = s.top();
                s.pop();

                if (visited.find(curNode) == visited.end()) {
                    visited.insert(curNode);
                }

                for (int i : adjList[curNode]) {
                    if (visited.find(i) == visited.end()) {
                        s.push(i);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected) << "\n"; // 2

    isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected) << "\n"; // 3

    return 0;
}

