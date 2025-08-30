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
#include <numeric>
#define ll long long

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) { // edge case
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        depth -=2;

        bool done = false;
        while (!q.empty() && !done) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode *cur = q.front();
                q.pop();

                if (depth == 0) {
                    TreeNode* lhs = new TreeNode(val);
                    if (cur->left) {
                        lhs->left = cur->left;
                    }
                    TreeNode* rhs = new TreeNode(val);
                    if (cur->right) {
                        rhs->right = cur->right;
                    }

                    cur->left = lhs;
                    cur->right = rhs;
                    done = true;
                } else {
                    if (cur->left) {
                        q.push(cur->left);
                    }
                    if (cur->right) {
                        q.push(cur->right);
                    }
                }
            }
            depth--;
        }
        return root;
    }
};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    return 0;
}

