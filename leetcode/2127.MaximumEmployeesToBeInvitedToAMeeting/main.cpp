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
    int maximumInvitations(vector<int>& favorite) {
        // topsort
        vector<int> indeg(favorite.size());

        for (int i = 0; i < favorite.size(); i++) {
            int u = i;
            int v = favorite[u];
            indeg[v]++;
        }
        vector<int> lengths(favorite.size(), 1); // contains the longest chain from any node up to this node
        queue<int> q; // contains nodes with indeg == 0
        vector<int> visited(favorite.size(), 0);

        for (int i = 0; i < indeg.size(); i++) {
            if (indeg[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }

        while (!q.empty()) { // handle all non-cyclic nodes
            int u = q.front();
            q.pop();

            indeg[favorite[u]]--;
            lengths[favorite[u]] = lengths[u] + 1;
            if (indeg[favorite[u]] == 0) {
                visited[favorite[u]] = 1;
                q.push(favorite[u]);
            }
        }

        int res = INT32_MIN;
        // for each remaining cycle, do a dfs and update the
        for (int i = 0; i < favorite.size(); i++) {
            if (!visited[i]) {
                dfs(favorite, lengths, i);
            }
        }
    }

    int dfs(vector<int>& favorite, vector<int>& lengths, int node)  {
        // returns the longest chain from any node up to this node

        stack<int> st;
        vector<int> visited(lengths.size(), 0);

        visited.push_back(node);
        st.push(node);

        while (!st.empty()) {
            int cur = st.top();
            st.pop();

            if () {

            }

            if (!visited[favorite[cur]])
        }

    }
};

int main() {
    fast();

    return 0;
}

