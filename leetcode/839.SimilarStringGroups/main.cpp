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
    vector<int> parent;
    int count;
    UnionFind(int n) {
        parent.resize(n);
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        while (parent[n] != n) {
            n = parent[n];
        }
        return n;
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        count--;
        parent[rootY] = rootX;
        return true;
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size());

        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                if (uf.find(i) == uf.find(j)) continue; // same set already, no need to check
                if (similar(strs[i], strs[j])) {
                    uf.unionSets(i, j);
                }
            }
        }
        return uf.getCount();
    }

    bool similar(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }
};

int main() {
    fast();
    Solution sol;
    string s1 = "rats";
    string s2 = "satr";
    string s3 = "star";
//    cout << sol.similar(s1, s2) << "\n"; // 1
//    cout << sol.similar(s1, s3) << "\n"; // 0
//    cout << sol.similar(s2, s3) << "\n"; // 1

    vector<string> strs = {"tars","rats","arts","star"};
    cout << sol.numSimilarGroups(strs) << "\n"; // 2

    strs = {"omv","ovm"};
    cout << sol.numSimilarGroups(strs) << "\n"; // 1

    strs = {"kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"};
    cout << sol.numSimilarGroups(strs) << "\n"; // 5
    return 0;
}

