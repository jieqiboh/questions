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

struct Node {
    // edges: go by character
    map<char,int> next;
    int link = -1;        // suffix link that this node points to
    bool output = false; // marks end of a pattern
};

vector<Node> trie(1); // root = 0

void add_string(const string &s) {
    int v = 0;
    for(char ch : s) {
        if (!trie[v].next.count(ch)) {
            trie[v].next[ch] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[ch];
    }
    trie[v].output = true;
}

void build_links() {
    queue<int> q;
    trie[0].link = 0;

    for (auto &p : trie[0].next) {
        int u = p.second;
        trie[u].link = 0;
        q.push(u);
    }

    while (!q.empty()) {
        int v = q.front(); q.pop(); // current char we are traversing in the trie
        for (auto &p : trie[v].next) {
            char ch = p.first; // character
            int u = p.second;  // idx in trie

            int link = trie[v].link;
            while (link != 0 && !trie[link].next.count(ch))
                link = trie[link].link;

            if (trie[link].next.count(ch))
                link = trie[link].next[ch];

            trie[u].link = link;
            trie[u].output = trie[u].output || trie[link].output;
            q.push(u);
        }
    }
}

// Search for any pattern in text; returns true if found
bool contains_pattern(const string &text) {
    int v = 0;
    for (char ch : text) {
        while (v != 0 && !trie[v].next.count(ch))
            v = trie[v].link;
        if (trie[v].next.count(ch))
            v = trie[v].next[ch];

        if (trie[v].output) return true;
    }
    return false;
}

int main() {
    fast();

    string sentence; cin >> sentence;
    int t; cin >> t;
    vector<string> patterns(t);
    for (auto& x : patterns) {
        cin >> x;
        add_string(x);
    }
    build_links();

    for (auto& pat : patterns) {
        if (contains_pattern(pat)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}

