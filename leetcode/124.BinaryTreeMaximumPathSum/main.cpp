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
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return INT_MIN; // not possible

        int rightOnly = maxPathSum(root->right);
        int leftOnly = maxPathSum(root->left);
        int rootOnly = root->val;
        int all = root->val + pathSumGain(root->right) + pathSumGain(root->left);
        int rootLeft = root->val + pathSumGain(root->left);
        int rootRight = root->val + pathSumGain(root->right);

        return max(rootOnly, max(rightOnly, max(leftOnly, max(all, max(rootLeft, rootRight)))));
    }

    int pathSumGain(TreeNode *root) {
        // return the max path sum where root MUST be included
        if (root == nullptr) return 0;
        return root->val + max(0, max(pathSumGain(root->left), pathSumGain(root->right)));
    }
};

int main() {
    fast();
    Solution sol;


    return 0;
}

