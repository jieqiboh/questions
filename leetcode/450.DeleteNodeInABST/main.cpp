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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr)
            return nullptr;

        if (root->val == key) {
            // Replace the root with the min node of the right subtree
            if (root->right) { // has right node
                root->val = getMin(root->right);
                root->right = deleteNode(root->right, root->val);
                return root;
            } else if (root->left) { // no right node, has left node
                TreeNode* leftChild = root->left;
                return leftChild;
            } else { // no children
                return nullptr;
            }
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    int getMin(TreeNode *root) {
        // root is guaranteed to exist
        if (root->left) {
            return getMin(root->left);
        } else {
            return root->val;
        }
    }
};



int main() {
    fast();

    return 0;
}

