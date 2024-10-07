// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
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

class UnionFind {                                // OOP style
private:
    vector<int> p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        UnionFind *uf = new UnionFind(n);

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // wt, u, v
        for (vector<int> vi : connections) {
            int u, v, w;
            u = vi[0]--;
            v = vi[1]--;
            w = vi[2];
            pq.push({w,u,v});
        }

        int cost = 0;
        while (uf->numDisjointSets() > 1 && !pq.empty()) {
            vector<int> top = pq.top();
            int u = top[1];
            int v = top[2];
            pq.pop();
            if (uf->isSameSet(u, v)) continue;
            cost += top[0];

            uf->unionSet(u, v);
        }
        return uf->numDisjointSets() == 1 ? cost : -1;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> connections = {{1,2,5},{1,3,6},{2,3,1}};
    cout << sol.minimumCost(n, connections) << "\n"; // 6

    n = 4;
    connections = {{1,2,3},{3,4,4}};
    cout << sol.minimumCost(n, connections) << "\n"; // -1

    return 0;
}
