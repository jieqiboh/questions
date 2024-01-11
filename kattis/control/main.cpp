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

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

int main() {
    fast();

    int num_ingredients = 500000;

    UnionFind UF(num_ingredients);

    int numlines; cin >> numlines;

    int res = 0;

    while (numlines--) {
        int n; cin >> n;
        set<int> ingr;
        while (n--) {
            int x; cin >> x;
            ingr.insert(x);
        }

        bool canConcoct = true;
        // For each elem in ingr, check that its parent is in ingr
        // For each elem in ingr, ensure that every elem in its disjoint set is in ingr
        // automatic rejection: If sizeOfSet(i) > ingr.size()
        // If sizeOfSet(i) <= ingr.size()
        // maintain a set of parents and total set size
        map<int, long> ingr_parents;

        for (int x : ingr) {
            int parent = UF.findSet(x);
            if (UF.sizeOfSet(x) > ingr.size()) {
                canConcoct = false;
                break;
            }
            if (ingr_parents.find(parent) == ingr_parents.end()) { // new parent found
                ingr_parents[parent] = UF.sizeOfSet(x);
            } else {
                ingr_parents[parent]--;
            }
            // by the end, the map of parents should all have value 1 only
        }
        for (auto& kv : ingr_parents) {
            if (canConcoct == false) break;
            if (kv.second != 1) {
                canConcoct = false;
                break;
            }
        }
        if (canConcoct) {
            int x = *ingr.begin();
            for (int y : ingr) {
                UF.unionSet(x, y);
            }
            res++;
        }
    }
    cout << res;

    return 0;
}

