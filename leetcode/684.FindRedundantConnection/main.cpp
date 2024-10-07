#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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

class UnionFind {
    private:
      vi p, rank, setSize;
      int numSets;
    public:
    // OOP style
    // vi p is the key part
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0); // optional speed up
        setSize.assign(N, 1); // optional feature
        numSets = N; // optional feature
    };

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> nodes;
        for (vector<int> edge : edges) {
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }
        UnionFind *uf = new UnionFind(nodes.size());

        for (vector<int> edge : edges) {
            int i = edge[0];
            int j = edge[1];
            if (!uf->isSameSet(i, j)) {
                uf->unionSet(i, j);
            } else {
                return edge;
            }
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> res = sol.findRedundantConnection(edges);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    res = sol.findRedundantConnection(edges);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

