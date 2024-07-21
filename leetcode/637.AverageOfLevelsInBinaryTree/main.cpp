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
    cin.tie(NULL); cout.tie(NULL);
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;

        q.push(root);
        int cur_size = 1;
        while (!q.empty()) {
            int new_size = 0;
            double val = 0;
            for (int i = 0; i < cur_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                val += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                    new_size++;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    new_size++;
                }
            }
            res.push_back(val / cur_size);
            cur_size = new_size;
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;

    // Manually constructing the tree from the given level-order array [3, 9, 20, null, null, 15, 7]

    // Level 0
    TreeNode* root = new TreeNode(3);

    // Level 1
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    // Level 2
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<double> res = sol.averageOfLevels(root);
    for (auto& x : res) {
        cout << x << " ";
    }

    return 0;
}

