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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val <= p->val && root->val <= q->val) {
            return root;
        } else if (root->val >= p->val && root->val >= q->val) {
            return root;
        }
        if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > p->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};

int main() {
    fast();

    return 0;
}

