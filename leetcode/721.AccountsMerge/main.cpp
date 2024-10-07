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
    Solution sol;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    vector<vector<string>> res = sol.accountsMerge(accounts);
    for (vector<string> vs : res) {
        for (string s : vs) {
            cout << s << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    accounts = {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
    res = sol.accountsMerge(accounts);
    for (vector<string> vs : res) {
        for (string s : vs) {
            cout << s << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    accounts = {{"David","David0@m.co","David1@m.co"},
                {"David","David3@m.co","David4@m.co"},
                {"David","David4@m.co","David5@m.co"},
                {"David","David2@m.co","David3@m.co"},
                {"David","David1@m.co","David2@m.co"}};
    res = sol.accountsMerge(accounts);
    for (vector<string> vs : res) {
        for (string s : vs) {
            cout << s << " ";
        }
        cout << "\n";
    }

    return 0;
}
