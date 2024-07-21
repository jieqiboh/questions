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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode *root) {
        // flattens this tree into a linked list, and returns ptr to the tail end
        if (root == nullptr) {
            return nullptr;
        } else {
            TreeNode *leftTail = dfs(root->left);
            TreeNode *rightTail = dfs(root->right);
            if (leftTail) {
                leftTail->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                return leftTail;
            }
            if (rightTail) return rightTail;
            return root;
        }
    }
};

int main() {
    fast();

    // Construct the tree manually
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Create a Solution object and call the flatten method
    Solution solution;
    solution.flatten(root);

    return 0;

    return 0;
}

