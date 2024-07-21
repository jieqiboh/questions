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
    cin.tie(NULL);
    cout.tie(NULL);
}


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // referenced william fiset's lca video
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<TreeNode*, int> last; // maps TreeNodes to their latest index in the node / depth arr in the eulerian tour
        vector<TreeNode*> nodes(0);
        vector<int> depth(0);

        dfs(root, depth, nodes, last, 0);
//        for (auto& x : depth) {
//            cout << x << " ";
//        }
//        cout << "\n";
//
//        for (auto& t: nodes) {
//            cout << t->val << " ";
//        }
//        cout << "\n";

        int idxStart = min(last[p], last[q]);
        int idxEnd = max(last[p], last[q]);
//        cout << idxStart << " " << idxEnd;
        int minDepthIdx;
        for (int i = idxStart; i <= idxEnd; i++) {
            if (depth[i] < depth[minDepthIdx]) {
                minDepthIdx = i;
            }
        }
        return nodes[minDepthIdx];
    }
    void dfs(TreeNode* root, vector<int>& depth, vector<TreeNode*>& nodes, unordered_map<TreeNode*, int>& last, int depthVal) {
        // do eulerian tour and populate depth and node tables
        if (root == nullptr) {
            return;
        } else {
            last[root] = nodes.size(); // use latest index
            nodes.push_back(root);
            depth.push_back(depthVal);
            if (root->left) {
                dfs(root->left, depth, nodes, last, depthVal + 1);
                last[root] = nodes.size(); // use latest index
                nodes.push_back(root);
                depth.push_back(depthVal);
            }
            if (root->right) {
                dfs(root->right, depth, nodes, last, depthVal + 1);
                last[root] = nodes.size(); // use latest index
                nodes.push_back(root);
                depth.push_back(depthVal);
            }
        }
    }
};

int main() {
    fast();
    // Construct the tree manually
    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    root->left = node5;
    root->right = node1;

    node5->left = node6;
    node5->right = node2;

    node1->left = node0;
    node1->right = node8;

    node2->left = node7;
    node2->right = node4;

    // Nodes p and q
    TreeNode* p = node4;
    TreeNode* q = node5;

    Solution sol;
    sol.lowestCommonAncestor(root, p, q);

    // Print the values of p and q
//    std::cout << "Node p value: " << p->val << std::endl;
//    std::cout << "Node q value: " << q->val << std::endl;

    // Clean up dynamically allocated memory
    delete node4;
    delete node7;
    delete node2;
    delete node6;
    delete node8;
    delete node0;
    delete node1;
    delete node5;
    delete root;

    return 0;

    return 0;
}

