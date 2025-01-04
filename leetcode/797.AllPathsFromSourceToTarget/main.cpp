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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<int>> res;
        vector<int> cur = {0};
        set<int> visited;
        visited.insert(0);
        backtrack(visited, 0, target, cur, res, graph);
        return res;
    }

    void backtrack(set<int>& visited, int i, int target, vector<int>& cur, vector<vector<int>>& res, vector<vector<int>>& graph) {
        if (i == target) {
            res.push_back(cur);
        } else {
            for (int nbr : graph[i]) {
                if (visited.find(nbr) != visited.end()) continue;
                cur.push_back(nbr);
                visited.insert(nbr);
                backtrack(visited, nbr, target, cur, res, graph);
                cur.pop_back();
                visited.erase(nbr);
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> res = sol.allPathsSourceTarget(graph);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

