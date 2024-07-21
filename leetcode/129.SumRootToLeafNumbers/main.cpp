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
    int sumNumbers(TreeNode *root) {
        int res = 0;
        dfs(res, root, 0);
        return res;
    }

    void dfs(int &res, TreeNode *node, int cur) {
        if (node == nullptr) {
            return;
        } else {
            cur *= 10;
            cur += node->val;
            if (node->left == nullptr && node->right == nullptr) {
                res += cur;
                return;
            }
            if (node->right) {
                dfs(res, node->right, cur);
            }
            if (node->left) {
                dfs(res, node->left, cur);
            }
        }
    }
};

int main() {
    fast();
    // Manually construct the tree [4, 9, 0, 5, 1]
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    Solution solution;
    int result = solution.sumNumbers(root);
    std::cout << "Sum of all root-to-leaf numbers: " << result << std::endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

