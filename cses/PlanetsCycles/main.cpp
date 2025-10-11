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

int n;

void dfs(vector<int>& res, vector<int>& graph, int start, vector<int>& visited) {
    int cur = start;
    vector<int> path;

    while (!visited[cur]) {
        if (res[cur] != 0) break;
        visited[cur] = true;
        path.push_back(cur);
        cur = graph[cur];
    }

    if (res[cur] != 0) {
        int len = res[cur];
        for (int i = (int)path.size() - 1; i >= 0; --i) {
            res[path[i]] = ++len;
        }
    } else {
        // cycle found
        int idx = 0;
        while (idx < path.size() && path[idx] != cur) idx++;

        int cycle_len = path.size() - idx;
        for (int i = idx; i < path.size(); i++)
            res[path[i]] = cycle_len;

        for (int i = idx - 1; i >= 0; i--)
            res[path[i]] = res[graph[path[i]]] + 1;
    }
}

int main() {
    fast();

    cin >> n;
    vector<int> graph(n+1); // maps each node to its next node
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        graph[i] = x;
    }

    vector<int> res(n+1, 0);
    vector<int> visited(n+1, 0);

    for (int i = 1; i <= n; i++) {
        if (res[i] == 0) {
            dfs(res, graph, i, visited);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}

