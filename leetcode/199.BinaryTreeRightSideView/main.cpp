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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        bool isQ1 = true; // indicates current queue to append new nodes to
        vector<int> res;

        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            if (isQ1) {
                while (q1.size() != 1) {
                    TreeNode* node = q1.front();
                    q1.pop();
                    if (node->left != nullptr) {
                        q2.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q2.push(node->right);
                    }
                }
                res.push_back(q1.front()->val);
                TreeNode* node = q1.front();
                if (node->left != nullptr) {
                    q2.push(node->left);
                }
                if (node->right != nullptr) {
                    q2.push(node->right);
                }
                q1.pop();
                isQ1 = false;
            } else {
                while (q2.size() != 1) {
                    TreeNode* node = q2.front();
                    q2.pop();
                    if (node->left != nullptr) {
                        q1.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q1.push(node->right);
                    }
                }
                res.push_back(q2.front()->val);
                TreeNode* node = q2.front();
                if (node->left != nullptr) {
                    q1.push(node->left);
                }
                if (node->right != nullptr) {
                    q1.push(node->right);
                }
                q2.pop();
                isQ1 = true;
            }
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    // Level 0
    TreeNode* root = new TreeNode(1);

    // Level 1
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Level 2
    root->left->left = nullptr;
    root->left->right = new TreeNode(5);
    root->right->left = nullptr;
    root->right->right = new TreeNode(4);

    vector<int> res = sol.rightSideView(root);
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}

