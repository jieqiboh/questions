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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        } else {
            TreeNode* left = root->left;
            TreeNode* right= root->right;
            return symmetric(left, right);
        }
    }

    bool symmetric(TreeNode *p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (p->val == q-> val) {
            TreeNode* p_right = p->right;
            TreeNode* p_left = p->left;
            TreeNode* q_left = q->left;
            TreeNode* q_right= q->right;
            return symmetric(p_right, q_left) && symmetric(p_left, q_right);
        } else {
            return false;
        }
    }
};

int main() {
    fast();

    return 0;
}

