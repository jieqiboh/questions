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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tempList = {};
        int curSum = 0;
        backtrack(res, tempList, root, curSum, targetSum);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& tempList, TreeNode *root, int curSum, int& targetSum) {
        if (root == nullptr) return;

        tempList.push_back(root->val);
        curSum += root->val;

        if (root->left == nullptr && root->right == nullptr && curSum == targetSum) {
            res.push_back(tempList);
        } else {
            backtrack(res, tempList, root->left, curSum, targetSum);
            backtrack(res, tempList, root->right, curSum, targetSum);
        }
        tempList.pop_back();
    }
};

int main() {
    fast();

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;
    vector<vector<int>> res = sol.pathSum(root, targetSum);
    for (auto& v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

