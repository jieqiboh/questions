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
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        int r1Val = -1;
        int r2Val = -1;
        if (root1 != nullptr) {
            r1Val = root1->val;
        }
        if (root2 != nullptr) {
            r2Val = root2->val;
        }
        if (r1Val != r2Val) {
            return false;
        }
        // noflip
        bool noFlipChildren = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);

        // flip
        TreeNode *tmp = root1->left;
        root1->left = root1->right;
        root1->right = tmp;
        bool flipChildren = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        return flipChildren || noFlipChildren;
    }
};

int main() {
    fast();
    Solution sol;


    return 0;
}

