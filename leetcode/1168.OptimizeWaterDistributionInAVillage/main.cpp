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
public:
    UnionFind(int N) : unionFind(N) {
        for (int i = 0; i < N; ++i)
            unionFind[i] = i;
    }

    void merge(int key1, int key2) {
        key1 = get(key1);
        key2 = get(key2);
        if (key1 == key2) return;
        unionFind[key2] = key1;
    }

    int get(int key) {
        while (key != unionFind[key])
            key = unionFind[key] = unionFind[unionFind[key]];
        return key;
    }

private:
    vector<int> unionFind;
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        UnionFind uf(n + 1);
        // treat wells as digging a path to a water src @ node 0
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // cost, src, dst

        for (int i = 0; i < wells.size(); i++) {
            pq.push({wells[i], i + 1, 0});
        }

        for (vector<int> pipe : pipes) {
            pq.push({pipe[2], pipe[0], pipe[1]});
        }

        int res = 0;
        while (!pq.empty()) {
            vector<int> top = pq.top();
            int src = top[1];
            int dst = top[2];
            int cost = top[0];
            pq.pop();

            // if same set, continue
            if (uf.get(src) == uf.get(dst)) {
                continue;
            } else {
                uf.merge(src, dst);
                res += cost;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 3;
    vector<int> wells = {1,2,2};
    vector<vector<int>> pipes = {{1,2,1},{2,3,1}};
    cout << sol.minCostToSupplyWater(n, wells, pipes) << "\n"; // 3

    return 0;
}

