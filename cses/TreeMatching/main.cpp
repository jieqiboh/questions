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

unordered_map<int, vector<int>> adjList; // adjacency list
unordered_set<int> done;
int res = 0;

void dfs(int pre, int cur) {
    for (int nbr : adjList[cur]) {
        if (nbr != pre) {
            dfs(cur, nbr);
            if (!done.count(cur) && !done.count(nbr)) {
                done.insert(cur);
                done.insert(nbr);
                res++;
            }
        }
    }
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    dfs(-1, 1);

    cout << res << '\n';
    return 0;
}

