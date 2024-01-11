#include "vector"
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == nullptr) {
            return vector<int>{};
        }

        res.push_back(root->val);

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal((root->right));

        for (int x : left) res.push_back(x);

        for (int y : right) res.push_back(y);

        return res;
    }
};

int main() {
    // Create the tree structure
    TreeNode *root = new TreeNode(3);
    root->left = nullptr;
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(8);

    // Printing the structure of the tree
    std::cout << "Tree structure:" << std::endl;
    std::cout << "       3" << std::endl;
    std::cout << "        \\" << std::endl;
    std::cout << "         5" << std::endl;
    std::cout << "        / \\" << std::endl;
    std::cout << "       2   8" << std::endl;

    // You can now work with the 'root' pointer and traverse the tree as needed.
    auto sol = Solution();
    vector<int> res = sol.preorderTraversal(root);

    for (int x : res) cout << x << " ";

    // Don't forget to deallocate memory when you're done with the tree to prevent memory leaks.
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}