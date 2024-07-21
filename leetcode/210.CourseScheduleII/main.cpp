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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // kahn's algo
        // queue q contains nodes with 0 incoming edges
        // vector<int> in_degree contains the incoming degree of each node
        // map<int, vector<int>> g contains the adjacency list for each node

        queue<int> q;
        unordered_map<int, vector<int>> g;
        vector<int> in_degree(numCourses);
        vector<int> order;

        // initialise adjList and in_degree
        for (vector<int> v : prerequisites) {
            // v[1] prereq, v[0]
            g[v[1]].push_back(v[0]);
            in_degree[v[0]] += 1;
        }

        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curNode = q.front();
            q.pop();
            order.push_back(curNode);

            for (int neighbour : g[curNode]) {
                in_degree[neighbour]--;
                if (in_degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        if (order.size() != numCourses) {
            return vector<int>{};
        }
        return order;
    }
};

int main() {
    fast();
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> res = sol.findOrder(numCourses, prerequisites);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

