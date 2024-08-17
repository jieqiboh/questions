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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> r1_leaves;
        vector<int> r2_leaves;

        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        traverse(r1_leaves, root1);
        traverse(r2_leaves, root2);
        if (r1_leaves.size() != r2_leaves.size()) return false;
        for (int i = 0; i < r1_leaves.size(); i++) {
            if (r1_leaves[i] != r2_leaves[i]) {
                return false;
            }
        }
        return true;
    }

    void traverse(vector<int>& leaves, TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
        } else {
            if (root->left != nullptr) {
                traverse(leaves, root->left);
            }
            if (root->right != nullptr) {
                traverse(leaves, root->right);
            }
        }
    }
};

int main() {
    fast();

    return 0;
}

