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
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, queue<int>> adjList;
        unordered_map<int,int> indeg; // maps nodes to their in degree
        unordered_map<int,int> outdeg; // maps nodes to their out degree

        vector<int> res;

        for (vector<int> p : pairs) {
            int start = p[0];
            int end = p[1];
            adjList[start].push(end);
            indeg[end]++;
            outdeg[start]++;
        }

        // find start node
        int start_node = 0;
        for (auto& p : adjList) {
            if (outdeg[p.first] - indeg[p.first] == 1) {
                start_node = p.first;
                break;
            }
            if (outdeg[p.first] > 0) start_node = p.first;
        }

        // perform dfs
        dfsIter(adjList, res, start_node);
        reverse(res.begin(), res.end());
        vector<vector<int>> result;
        for (int i = 0; i < res.size() - 1; i++) {
            result.push_back({res[i], res[i+1]});
        }
        return result;
    }
    void dfs(unordered_map<int, queue<int>>& adjList, vector<int>& res, int at, unordered_map<int,int>& outdeg) {
        while (outdeg[at] != 0) {
            int next_node = adjList[at].front();
            adjList[at].pop();
            adjList[at].push(next_node); // move next node to back of queue
            outdeg[at]--;

            dfs(adjList, res, next_node, outdeg);
        }
        res.push_back(at);
    }
    void dfsIter(unordered_map<int, queue<int>>& adjList, vector<int>& res, int at) {
        stack<int> st;
        st.push(at);

        while (!st.empty()) {
            int v = st.top();
            if (adjList[v].empty()) {
                res.push_back(v);
                st.pop();
            } else {
                int next_node = adjList[v].front();
                adjList[v].pop();
                st.push(next_node);
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> pairs = {{5,1},{4,5},{11,9},{9,4}};
    vector<vector<int>> res = sol.validArrangement(pairs);
    for (vector<int> vi : res) {
        cout << "[" << vi[0] << " " << vi[1] << "]";
    }
    cout << "\n";

    pairs = {{5,1},{4,5},{4,6},{6,4},{11,9},{9,4}};
    res = sol.validArrangement(pairs);
    for (vector<int> vi : res) {
        cout << "[" << vi[0] << " " << vi[1] << "]";
    }
    cout << "\n";

    pairs = {{1,3},{3,2},{2,1}};
    res = sol.validArrangement(pairs);
    for (vector<int> vi : res) {
        cout << "[" << vi[0] << " " << vi[1] << "]";
    }
    cout << "\n";

    pairs = {{1,2},{1,3},{2,1}};
    res = sol.validArrangement(pairs);
    for (vector<int> vi : res) {
        cout << "[" << vi[0] << " " << vi[1] << "]";
    }
    cout << "\n";

    return 0;
}

