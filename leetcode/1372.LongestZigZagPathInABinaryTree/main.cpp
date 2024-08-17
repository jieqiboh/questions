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
    int longestZigZag(TreeNode *root) {
        int maxLen = 0;
        dfs(root->left, false, 1, maxLen);
        dfs(root->right, true, 1, maxLen);
        return maxLen;
    }
    void dfs(TreeNode *root, bool dir, int curLen, int& maxLen) {
        // dir denotes if node previously travelled right
        if (root == nullptr) {
            return;
        } else {
            maxLen = max(maxLen, curLen);
            if (dir) {
                dfs(root->left, false, curLen+1, maxLen);
                dfs(root->right, true, 1, maxLen);
            } else {
                dfs(root->left, false, 1, maxLen);
                dfs(root->right, true, curLen+1, maxLen);
            }
        }

    }
};


TreeNode* createTree() {
    // Level 4
    TreeNode* node14 = new TreeNode(1);

    // Level 3
    TreeNode* node9 = new TreeNode(1);
    TreeNode* node8 = new TreeNode(1, nullptr, node14);
    TreeNode* node7 = new TreeNode(1);

    // Level 2
    TreeNode* node5 = new TreeNode(1, node8, node9);
    TreeNode* node4 = new TreeNode(1, node7, nullptr);

    // Level 1
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(1, node4, node5);

    // Level 0 (Root)
    TreeNode* root = new TreeNode(1, nullptr, node2);

    return root;
}

int main() {
    fast();
    Solution sol;
    TreeNode *root = createTree();
    cout << sol.longestZigZag(root) << "\n"; // 3

    return 0;
}

