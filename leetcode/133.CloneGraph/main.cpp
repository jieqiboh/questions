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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr; // Early return if node is nullptr

        unordered_map<Node*, Node*> created; // maps old nodes to newly created nodes
        queue<Node*> q;

        q.push(node);
        created[node] = new Node(node->val); // Create the first node

        while (!q.empty()) {
            Node* curNode = q.front();
            q.pop();

            for (Node* neighbour : curNode->neighbors) {
                if (created.find(neighbour) == created.end()) { // new neighbour node doesn't exist yet
                    created[neighbour] = new Node(neighbour->val); // Create the new neighbour node
                    q.push(neighbour); // Push the new neighbour onto the queue
                }
                created[curNode]->neighbors.push_back(created[neighbour]); // Add the cloned neighbour to the current new node's neighbors
            }
        }
        return created[node];
    }
};
int main() {
    // Create an example graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution sol;
    // Clone the graph
    Node* clonedGraph = sol.cloneGraph(node1);

    // Output the values of the cloned graph (example)
    std::cout << "Cloned Node Value: " << clonedGraph->val << "\n";
    for (Node* neighbor : clonedGraph->neighbors) {
        std::cout << "Neighbor Value: " << neighbor->val << "\n";
    }

    // Clean up dynamically allocated memory (example, not complete cleanup)
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    // You would also need to delete the cloned graph nodes here.

    return 0;
}

