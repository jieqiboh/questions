#include "iostream"
using namespace std;

//Definition for a binary tree node.
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
    int maxDepth(TreeNode* root) {
        int count = 0;

        if (root == nullptr) return 0;
        count++;
        return count + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int maxDepthL = maxDepth(root->left);
        int maxDepthR = maxDepth(root->right);

        if ((maxDepthL - maxDepthR > 1) || (maxDepthR - maxDepthL > 1)) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};


TreeNode* createBinaryTreeOne() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->left = nullptr; // Represents null
    root->right->right = nullptr; // Represents null
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    return root;
}

TreeNode* createBinaryTreeTwo() {
    TreeNode* root = new TreeNode(1);
    return root;
}

TreeNode* createBinaryTreeThree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->left = nullptr; // Represents null
    root->right->right = nullptr; // Represents null
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    return root;
}

int main() {
    auto sol = Solution();

    cout << sol.maxDepth(createBinaryTreeOne()) << endl;
    cout << sol.maxDepth(createBinaryTreeTwo()) << endl;
    cout << sol.maxDepth(createBinaryTreeThree()) << endl;

    cout << sol.isBalanced(createBinaryTreeOne()) << endl;
    cout << sol.isBalanced(createBinaryTreeTwo()) << endl;
    cout << sol.isBalanced(createBinaryTreeOne()) << endl;

    return 0;
}

