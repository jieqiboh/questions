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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indeg(numCourses, 0);
        unordered_map<int, vector<int>> dagList; // maps each node to nodes it points to
        unordered_map<int, vector<int>> revDagList; // maps each node to its neighbours
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false)); // reachable[u][v] means v is reachable from u in the DAG

        for (auto& vi : prerequisites) {
            int u = vi[0];
            int v = vi[1];
            indeg[v]++; // u points to v
            dagList[u].push_back(v);
            revDagList[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++) {
            reachable[i][i] = true; // courses can reach themselves
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int qSz = q.size();
            for (int i = 0; i < qSz; i++) {
                int cur = q.front();
                q.pop();

                // for each child that points to cur, if other nodes can reach it
                // mark them as able to reach cur
                for (int prev : revDagList[cur]) {
                    for (int j = 0; j < numCourses; j++) {
                        if (reachable[j][prev] && j != prev) {
                            reachable[j][cur] = true;
                        }
                    }
                }

                for (int nxt : dagList[cur]) {
                    indeg[nxt]--;
                    reachable[cur][nxt] = true;
                    if (indeg[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }
        }

        vector<bool> res;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            res.push_back(reachable[u][v]);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2}};
    vector<vector<int>> queries={{0,1},{3,1}};
    vector<bool> res = sol.checkIfPrerequisite(numCourses, prerequisites, queries);
    for (bool b : res) {
        cout << b << " ";
    }
    cout << "\n";

    return 0;
}

