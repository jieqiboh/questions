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

struct TrieNode {
    TrieNode* child[2];

    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

void insert(TrieNode* root, int x) {
    TrieNode* cur = root;
    for (int bit = 31; bit >= 0; bit--) {
        int b = (x >> bit) & 1;
        if (!cur->child[b])
            cur->child[b] = new TrieNode();
        cur = cur->child[b];
    }
}

int query(TrieNode* root, int x) {
    // for each prefix, find the max prefix xor
    TrieNode* cur = root;
    int res = 0; // construct res
    for (int bit = 31; bit >= 0; bit--) {
        int b = (x >> bit) & 1;
        if (cur->child[1 - b]) {
            res |= (1 << bit);
            cur = cur->child[1-b];
        } else {
            cur = cur->child[b];
        }
    }
    return res;
}

int main() {
    fast();

    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    TrieNode* root = new TrieNode();

    int cur = 0;
    insert(root, 0);
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        cur ^= v[i];
        maxVal = max(maxVal, query(root, cur));

        insert(root, cur);
    }

    cout << maxVal;

    return 0;
}

