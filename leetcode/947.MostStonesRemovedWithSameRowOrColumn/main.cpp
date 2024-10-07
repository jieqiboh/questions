#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
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

    int numDisjointSets() { return numSets; }      // optional

    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

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
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> x; // maps x-coord to stones sharing it
        unordered_map<int, int> y; // maps y-coord to stones sharing it
        int res = 0;

        for (vector<int> coord: stones) {
            x[coord[0]]++;
            y[coord[1]]++;
        }
        unordered_set<int> visited_x; // x-coords
        unordered_set<int> visited_y; // y-coords
        for (vector<int> coord: stones) {
            if (visited_x.find(coord[0]) == visited_x.end() && visited_y.find())
        }
        return stones.size() - res;
    }
};

int main() {
    fast();
    // union sets if they share x or y coords

    return 0;
}

