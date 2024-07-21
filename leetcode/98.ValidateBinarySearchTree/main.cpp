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
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        } else {
            return validBST(root, INT64_MIN, INT64_MAX);
        }
    }
    bool validBST(TreeNode* root, long min_val, long max_val) { // root has to be in the range (min_val, max_val)
        if (root == nullptr) {
            return true;
        } else {
            if (root->val <= min_val || root->val >= max_val) return false;
            if (root->left != nullptr && root->right != nullptr) {
               return validBST(root->left, min_val, root->val) && validBST(root->right, root->val, max_val);
            } else if (root->left != nullptr) {
                return validBST(root->left, min_val, root->val);
            } else if (root->right != nullptr) {
                return validBST(root->right, root->val, max_val);
            } else {
                return true;
            }
        }
    }
};

int main() {
    fast();

    return 0;
}

