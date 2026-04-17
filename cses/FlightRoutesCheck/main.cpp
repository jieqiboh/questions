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
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int UNVISITED = -1;
int n, m;
int id = 0;
int sccCount = 0;

// Graph + Tarjan state
vector<vector<int>> g;
vector<int> ids, low, sccId;
vector<bool> onStack;
stack<int> st;

void dfs(int at) {
    st.push(at);
    onStack[at] = true;
    ids[at] = low[at] = id++;

    // visit all neighbours and min low-link on callback
    for (int to : g[at]) {
        if (ids[to] == UNVISITED) dfs(to);
        if (onStack[to]) {
            low[at] = min(low[at], low[to]);
        }
    }

    // After having visited all neighbours of 'at'
    // if we are at the start of an SCC, empty the seen stack until we're back
    // to the start of the SCC
    if (ids[at] == low[at]) {
        while (!st.empty()) {
            int node = st.top();
            onStack[node] = false;
            st.pop();
            low[node] = ids[at];
            sccId[node] = sccCount;
            if (node == at) break;
        }
        sccCount++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n + 1, {});       // adjacency list
    ids.assign(n + 1, UNVISITED);
    low.assign(n + 1, 0);
    sccId.assign(n + 1, -1);
    onStack.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (ids[i] == UNVISITED)
            dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        if (sccId[i] != sccId[1]) {
            cout << "NO\n";
            if (sccId[1] > sccId[i]) cout << i << " " << 1;
            else cout << 1 << " " << i;
            return 0;
        }
    }
    cout << "YES";


    return 0;
}

