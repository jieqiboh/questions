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

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vector<int> parent, sz;

public:
    UnionFind(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        while (parent[n] != n) {
            n = find(parent[n]);
        }
        return n;
    }

    bool unionSets(int x, int y) {
        // to union a set, we just need to assign a parent to be the other
        // returns true if a union happened
        // union by rank
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        if (sz[rootX] < sz[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        sz[rootX] += sz[rootY];
        return true;
    }
};;

int main() {
    int n, m; cin >> n >> m;
    UnionFind uf(n+1);

//    int totSets = n;
    while (m--) {
        int x, y; cin >> x >> y;
        uf.unionSets(x, y);
    }

    unordered_set<int> finalParents;
    for (int i = 1; i <= n; i++) {
        finalParents.insert(uf.find(i));
    }

    vector<int> finalParentsVec(finalParents.begin(), finalParents.end());
    cout << finalParentsVec.size() - 1 << "\n";
    for (int i = 0; i < finalParentsVec.size() - 1; i++) {
        cout << finalParentsVec[i] << " " << finalParentsVec[i+1] << "\n";
    }

    return 0;
}
