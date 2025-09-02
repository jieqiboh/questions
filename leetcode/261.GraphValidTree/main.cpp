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

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        while (parent[n] != n) {
            n = parent[n];
        }
        return n;
    }

    bool unionSets(int x, int y) {
        // to union a set, we just need to assign a parent to be the other
        // returns true if a union happened
        bool unioned = false;
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            unioned = true;
            parent[rootY] = rootX;
        }
        return unioned;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        if (edges.size() != n - 1) return false;
        for (int i = 0; i < edges.size(); i++) {
            if (!uf.unionSets(edges[i][0], edges[i][1])) return false;
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    cout << sol.validTree(n, edges) << "\n"; // 1

    n = 5;
    edges = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << sol.validTree(n, edges) << "\n"; // 0

    return 0;
}

