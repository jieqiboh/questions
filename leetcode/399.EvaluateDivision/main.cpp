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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adjList;

        for (int  i = 0; i < equations.size(); i++) {
            string c = equations[i][0];
            string d = equations[i][1];
            adjList[c].push_back(make_pair(d, values[i]));
            adjList[d].push_back(make_pair(c, 1.0 / values[i]));
        }

        vector<double> res;
        for (vector<string> query : queries) {
            res.push_back(bfs(query, adjList));
        }

        return res;
    }

    double bfs(vector<string> equation, unordered_map<string, vector<pair<string, double>>>& adjList) {
        string x = equation[0];
        string y = equation[1];
        queue<pair<string, double>> q; // contains current var and val
        if (adjList.find(x) == adjList.end() || adjList.find(y) == adjList.end()) return -1.0; // not found

        unordered_set<string> visited;
        q.push(make_pair(x, 1.0));

        while (!q.empty()) {
            pair<string, double> node = q.front(); // cur var and val
            q.pop();
            visited.insert(node.first);

            if (node.first == y) { // node found
                return node.second;
            } else {
                vector<pair<string, double>> v = adjList.find(node.first)->second;
                for (pair<string, double> p : v) {
                    if (visited.find(p.first) != visited.end()) continue;
                    q.push(make_pair(p.first, node.second * p.second));
                }
            }
        }
        return -1.0; // not found
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    vector<double> res = sol.calcEquation(equations, values, queries);

    for (auto& x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

