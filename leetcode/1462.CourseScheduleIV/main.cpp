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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // pre-compute all courses that a course is a pre-req of
        vector<set<int>> prereqs(numCourses);

        unordered_map<int,vector<int>> adjList;
        for (vector<int> vi : prerequisites) {
            int u = vi[0];
            int v = vi[1];
            adjList[u].push_back(v);
        }

        for (int i = 0; i < numCourses; i++) {
            // do a bfs, adding the courses
            bfs(prereqs, adjList, i);
        }

        vector<bool> res;
        for (vector<int> query : queries) {
            int u = query[0];
            int v = query[1];
            if (prereqs[u].find(v) == prereqs[u].end()) {
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }
        return res;
    }

    void bfs(vector<set<int>>& prereqs, unordered_map<int, vector<int>>& adjList, int node) {
        // updates the set in prereqs[node] to contain all the courses that node is a prereq of
        queue<int> q;
        set<int> visited;

        q.push(node);
        visited.insert(node);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            prereqs[node].insert(cur);

            for (int nbr : adjList[cur]) {
                if (visited.find(nbr) == visited.end()) {
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    vector<vector<int>> queries = {{0,1},{1,0}};
    vector<bool> res = sol.checkIfPrerequisite(numCourses, prerequisites, queries);
    for (bool b : res) {
        cout << b << " ";
    }
    cout << "\n";

    numCourses = 14;
    prerequisites = {{9,3},{9,6},{9,5},{12,11},{12,8},{12,5},{12,13},{3,7},{3,13},{3,10},{11,5},{11,1},{8,7},{8,5},{8,10},{4,13},{4,10},{4,1},{7,5},{7,13},{0,6},{0,5},{0,2},{6,13},{6,2},{5,10},{5,1},{13,10}};
    queries = {{11,5},{7,9},{0,9},{12,3},{7,11},{4,13},{10,13},{10,13}};
    res = sol.checkIfPrerequisite(numCourses, prerequisites, queries);
    for (bool b : res) {
        cout << b << " ";
    }
    cout << "\n";

    return 0;
}

