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

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

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

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

int main() {
    fast();

    int numelem, numops; cin >> numelem >> numops;

    UnionFind UF(numelem);
    while (numops--) {
        char x; cin >> x;
        int a, b; cin >> a >> b;

        if (x == '?') {
            if (UF.isSameSet(a, b)) {
                cout << "yes" << '\n';
            } else {
                cout << "no" << '\n';
            }
        } else if (x == '=') {
            UF.unionSet(a, b);
        }
    }
    return 0;
}

