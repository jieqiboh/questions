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

class Solution {
public:
    vector<vector<int>> zigZagLevelOrder(TreeNode *root) {
        vector<vector<int>> res(0);
        if (root == nullptr) return res;
        deque<TreeNode*> q;
        bool isLeftToRight = true;

        q.push_front(root);
        int cur_size = 1;
        res.push_back({root->val});
        while (!q.empty()) {
            int new_size = 0;
            vector<int> level;
            if (isLeftToRight) {
                for (int i = 0; i < cur_size; i++) {
                    TreeNode* node = q.front();
                    q.pop_front();
                    if (node->right != nullptr) {
                        q.push_back(node->right);
                        level.push_back(node->right->val);
                        new_size++;
                    }
                    if (node->left != nullptr) {
                        q.push_back(node->left);
                        level.push_back(node->left->val);
                        new_size++;
                    }
                }
                isLeftToRight = false;
            } else {
                for (int i = 0; i < cur_size; i++) {
                    TreeNode* node = q.back();
                    q.pop_back();
                    if (node->left != nullptr) {
                        q.push_front(node->left);
                        level.push_back(node->left->val);
                        new_size++;
                    }
                    if (node->right != nullptr) {
                        q.push_front(node->right);
                        level.push_back(node->right->val);
                        new_size++;
                    }
                }
                isLeftToRight = false;
            }
            if (!level.empty()) res.push_back(level);
            cur_size = new_size;
        }
        return res;
    }
};

int main() {
    fast();

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

    Solution sol;
    vector<vector<int>> res = sol.zigZagLevelOrder(root);

    for (auto& x : res) {
        for (auto & y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }

    return 0;
}

