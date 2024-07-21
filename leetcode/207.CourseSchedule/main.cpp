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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList; // maps prereq to course

        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> v = prerequisites[i];
            int prereq = v[1]; // prereq is needed before taking cse
            int cse = v[0];
            adjList[prereq].push_back(cse);
        }

        for (auto& x : adjList) {
            cout << x.first << ": ";
            for (auto& y : x.second) cout << y << " ";
            cout << "\n";
        }

        for (auto& x : adjList) {
            int i = x.first;
            unordered_set<int> visited;
            unordered_set<int> recStack;
            if (dfs(i, adjList, visited, recStack)) return false;
        }
        return true;
    }

    bool dfs(int start, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, unordered_set<int>& recStack) {
        if (visited.find(start) == visited.end()) {
            // Mark current node as visited and as part of recStack
            visited.insert(start);
            recStack.insert(start);

            for (int child : adjList[start]) {
                if (visited.find(child) == visited.end() && dfs(child, adjList, visited, recStack)) {
                    return true;
                } else if (recStack.find(child) != recStack.end()) {
                    return true;
                }
            }
        }
        recStack.erase(start);
        return false;
    }
};

int main() {
    fast();

    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    cout << sol.canFinish(numCourses, prerequisites) << "\n\n"; // 1

    numCourses = 4;
    prerequisites = {{0,1},{2,0},{3,2},{1,2}};
    cout << sol.canFinish(numCourses, prerequisites) << "\n\n"; // 0

    numCourses = 2;
    prerequisites = {{0,1}};
    cout << sol.canFinish(numCourses, prerequisites) << "\n\n"; // 1
    
    prerequisites = {{1,4},{2,4},{3,1},{3,2}};
    numCourses = 5;
    cout << sol.canFinish(numCourses, prerequisites) << "\n\n"; // 1

    prerequisites = {{0,1},{0,2},{1,2}};
    numCourses = 3;
    cout << sol.canFinish(numCourses, prerequisites) << "\n\n"; // 1

    return 0;
}

