#include "iostream"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    int count = 0;

    if (root == nullptr)
      return 0;

    count++;

    count += max(maxDepth(root->left), maxDepth(root->right));

    return count;
  }
};

TreeNode *createBinaryTreeOne() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(9);
  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(11);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(13);
  root->right->right->left = new TreeNode(14);
  root->right->right->right = new TreeNode(15);

  return root;
}

TreeNode *createBinaryTreeTwo() {
  TreeNode *root = new TreeNode(1);
  return root;
}

int main() {
  auto sol = Solution();

  cout << sol.maxDepth(createBinaryTreeOne()) << endl;
  cout << sol.maxDepth(createBinaryTreeTwo()) << endl;

  return 0;
}
