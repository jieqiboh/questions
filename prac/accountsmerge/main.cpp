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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind *uf = new UnionFind(accounts.size());
        map<string,int> m; // maps email to acc idx, sorted lexicographically
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) != m.end()) { // exists another account idx with this email
                    uf->unionSet(i, uf->findSet(m[accounts[i][j]])); // union sets
                }
            }
            for (int j = 1; j < accounts[i].size(); j++) {
                m[accounts[i][j]] = i; // assign all the emails in this account to parent idx
            }
        }
        unordered_map<int,vector<string>> grps;
        for (auto& pair : m) {
            int parent = uf->findSet(pair.second);
            grps[parent].push_back(pair.first);
        }
        vector<vector<string>> res;
        for (auto& pair : grps) {
            vector<string> v = pair.second;
            int idx = pair.first;
            v.insert(v.begin(), accounts[idx][0]);
            res.push_back(v);
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<string>> accounts = {{"neet","a@gmail.com"},{"neet","b@gmail.com"},{"neet","a@gmail.com","b@gmail.com"}};
    vector<vector<string>> res = sol.accountsMerge(accounts);
    for (auto& vs : res) {
        for (auto s : vs) {
            cout << s << " ";
        }
        cout << "\n";
    }
    return 0;
}

