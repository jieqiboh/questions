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
    int pathSum(TreeNode *root, int targetSum) {
        // naive O(n^2) soln: for each node, do a dfs and increment res if path sum matches targetSum
        int res = 0;
        dfs_dfs(root, res, targetSum);
        return res;
    }

    void dfs_dfs(TreeNode *root, int& res, int targetSum) {
        // does a traversal, running a dfs on every node
        if (root == nullptr) return;
        dfs(root, 0, res, targetSum);
        dfs_dfs(root->left, res, targetSum);
        dfs_dfs(root->right, res, targetSum);
    }

    // THIS DOESN'T WORK, itll cause double additions which is wronggg
//    void dfs(TreeNode *root, int curSum, int& res, int targetSum) {
//        // curSum is the path sum from the root, up till excluding the current node
//        if (curSum == targetSum) {
//            res++;
//        }
//        if (root == nullptr) return;
//        dfs(root->left, curSum + root->val, res, targetSum);
//        dfs(root->right, curSum + root->val, res, targetSum);
//    }
    void dfs(TreeNode *root, long curSum, int& res, int targetSum) {
        // curSum is the path sum from the root, up till excluding the current node
        if (root == nullptr) return;
        curSum += root->val;

        // Check if curSum matches the targetSum
        if (curSum == targetSum) {
            res++;
        }
        dfs(root->left, curSum, res, targetSum);
        dfs(root->right, curSum, res, targetSum);
    }
};

int main() {
    fast();

    // Level 1 (Root)
    TreeNode* root = new TreeNode(10);

    // Level 2
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    // Level 3
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);

    // Level 4
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution sol;
    cout << sol.pathSum(root, 8) << "\n"; // 3

    return 0;
}

