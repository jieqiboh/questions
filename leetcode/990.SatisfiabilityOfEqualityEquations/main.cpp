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
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(200); // ascii z is 122

        for (string eqn : equations) {
            char u = eqn[0];
            char v = eqn[eqn.size() - 1];
            if (eqn[1] == '=') {
                uf.unionSet(u, v);
            }
        }

        for (string eqn : equations) {
            char u = eqn[0];
            char v = eqn[eqn.size() - 1];
            if (eqn[1] == '!') {
                if (uf.isSameSet(u, v)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    vector<string> equations = {"a==b","b!=a"};
    cout << sol.equationsPossible(equations) << "\n"; // 0

    equations = {"a==b","b==a"};
    cout << sol.equationsPossible(equations) << "\n"; // 1
    return 0;
}

