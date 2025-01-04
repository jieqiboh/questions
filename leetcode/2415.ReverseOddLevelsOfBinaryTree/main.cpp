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
    TreeNode *reverseOddLevels(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        } else {
            if (root->left && root->right)  {
                int leftVal = root->left->val;
                root->left->val = root->right->val;
                root->right->val = leftVal;

                root->left->left = reverseOddLevels(root->left->left);
                root->left->right = reverseOddLevels(root->left->right);
                root->right->left = reverseOddLevels(root->right->left);
                root->right->right = reverseOddLevels(root->right->right);
            }
        }
        return root;
    }
};

int main() {
    fast();

    return 0;
}

