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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

// Custom comparator for the priority queue
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second) {
            return a.first > b.first; // Compare by the first element if seconds are equal
        }
        return a.second > b.second; // Compare by the second element
    }
};

bool isValidSeq(vector<int> a, int n) {
    int nodes = n + 2;

    // Iterate in the Prufer sequence
    for (int i = 0; i < n; i++) {

        // If out of range
        if (a[i] < 1 || a[i] > nodes)
            return false;
    }

    return true;
}

int main() {
    fast();

    // Prufer sequence with Priority queue
    // Just need to know the algorithm tbh
    // Useful link here: https://www.geeksforgeeks.org/prufer-code-tree-creation/

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    
    int num; cin >> num;
    umap<int, int> val_count;
    int max_val = -1;
    vector<int> prufer_seq;

    while (num--) {
        int val; cin >> val;

        prufer_seq.push_back(val); // add to prufer sequence

        if (val > max_val) { // reassign max_val if new max found
            max_val = val;
        }

        if (val_count.find(val) == val_count.end()) { // val not encountered before
            val_count[val] = 1;
        } else { // val encountered before
            val_count[val] += 1;
        }
    }
    // for [1, max_val], push into pq
    for (int i = 1; i <= max_val; i++) {
        if (val_count.find(i) == val_count.end()) { // i not seen before
            val_count[i] = 1;
            pq.push(make_pair(i, 1));
        } else {
            int count = val_count[i] + 1;
            val_count[i] = count;
            pq.push(make_pair(i, count));
        }
    }
    set<int> unique;
    vector<int> soln;
    for (int u : prufer_seq) {
        pair<int, int> top = pq.top();
//        cout << top.first << " " << top.second << "\n";
        int v = top.first;
        soln.push_back(top.first);
        val_count[v] -= 1;
        val_count[u] -= 1;

//        cout << v << "\n";

        unique.insert(v);
        unique.insert(u);

        pq.pop();
        int u_count = val_count[u];
        int v_count = val_count[v];
        if (val_count[u] != 0) {
            pq.push(make_pair(u, u_count));
        }
        if (val_count[v] != 0) {
            pq.push(make_pair(v, v_count));
        }
    }
    if (unique.size() != (prufer_seq.size() + 1)) {
//        cout << "unique size: " << unique.size() << "\n";
//        cout << prufer_seq.size() << "\n";
        cout << "error";
    } else {
        for (int x : soln) cout << x << "\n";
    }
//    cout << "size at end: " << pq.size() << "\n";

    return 0;
}

