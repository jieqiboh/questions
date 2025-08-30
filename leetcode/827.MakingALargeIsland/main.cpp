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

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
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
    int largestIsland(vector<vector<int>>& grid) {
        UnionFind uf(grid.size() * grid[0].size());

        unordered_map<int,int> sz; // maps parent coord to the size of the island

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        // visited also contains the id of the island a coord is part of
        // union all 1s that are part of the same island

        int id = 1; // id of the current island being evaluated
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] && !visited[i][j]) {
                    // bfs on this coord, finding all connected 1s
                    dfs(i, j, uf, grid, sz, visited, id);
                    id++; // increment
                }
            }
        }
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[0].size(); j++) {
//                cout << visited[i][j] << " ";
//            }
//            cout << "\n";
//        }

//        for (pair<int,int> p : sz) {
//            cout << p.first << " " << p.second << "\n";
//        }

        vector<vector<int>> cellMaxes(grid.size(), vector<int>(grid[0].size(), 0));
        int res = 0;
        for (pair<int,int> p : sz) {
            res = max(res, p.second);
        }
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    int cellMax = 0;
                    set<int> ids; // contains unique ids found around a 0 cell
                    vector<int> sizes;
                    for (pair<int,int> dir : dirs) {
                        int newI = dir.first + i;
                        int newJ = dir.second + j;
                        if (newI < 0 || newI > grid.size() - 1 || newJ < 0 || newJ > grid[0].size() - 1) continue; // oob
                        if (visited[newI][newJ] == 0) continue; // not part of an island
                        ids.insert(visited[newI][newJ]);
                    }
                    for (int i : ids) {
                        sizes.push_back(sz[i]);
                    }
                    cellMaxes[i][j] = 1 + accumulate(sizes.begin(), sizes.end(), 0);
                }
                res = max(res, cellMaxes[i][j]);
            }
        }
        return res;
    }

    void dfs(int i, int j, UnionFind& uf, vector<vector<int>>& grid, unordered_map<int,int>& sz, vector<vector<int>>& visited, int& id) {
        queue<pair<int,int>> q;
        int islandSz = 0;
        q.push({i, j});
        visited[i][j] = id;

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();

            islandSz++;

            for (pair<int,int> dir : dirs) {
                int newI = cur.first + dir.first;
                int newJ = cur.second + dir.second;

                if (newI < 0 || newI > grid.size() - 1 || newJ < 0 || newJ > grid[0].size() - 1) continue; // oob
                if (grid[newI][newJ] == 0 || visited[newI][newJ]) continue;
                visited[newI][newJ] = id;
                q.push({newI, newJ});
            }
        }
        sz[id] = islandSz;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,1,0},{0,1,0},{0,0,1}};
    cout << sol.largestIsland(grid) << "\n"; // 5

    grid = {{1,1},{1,1}};
    cout << sol.largestIsland(grid) << "\n"; // 4

    grid = {{0,0},{0,0}};
    cout << sol.largestIsland(grid) << "\n"; // 1
    
    grid = {{0,0,0,0,0,0,0},
            {0,1,1,1,1,0,0},
            {0,1,0,0,1,0,0},
            {1,0,1,0,1,0,0},
            {0,1,0,0,1,0,0},
            {0,1,0,0,1,0,0},
            {0,1,1,1,1,0,0}};
    cout << sol.largestIsland(grid) << "\n"; // 18
    return 0;
}
