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

struct Node {
    int val;
    Node* prev;
    Node* next;
};

auto cmp = [](Node* a, Node* b) {
    return a->val > b->val;
};

priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);

void solve() {
    int n;
    cin >> n;

    vector<Node*> nodes(n);

    // build nodes
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        nodes[i] = new Node{x, nullptr, nullptr};
    }

    // build circular doubly linked list
    for (int i = 0; i < n; i++) {
        nodes[i]->prev = nodes[(i - 1 + n) % n];
        nodes[i]->next = nodes[(i + 1) % n];
    }

    // push all nodes into pq
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
    for (auto* node : nodes)
        pq.push(node);

    long long res = 0;

    for (int i = 0; i < n-1; i++) {
        Node* cur = pq.top();
        pq.pop();

        Node* L = cur->prev;
        Node* R = cur->next;

        // choose smaller neighbor
        Node* target = (L->val < R->val ? L : R);

        res += target->val;

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    cout << res << "\n";
}


int main() {
    fast();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

