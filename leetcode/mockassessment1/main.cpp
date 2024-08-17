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
    vector<int> largestValues(TreeNode *root) {
        vector<int> res = {};
        if (root == nullptr) return res;

        // do a bfs, appending max val to the frontier

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int maxVal = INT32_MIN;
            int q_size = q.size();

            for (int i = 0; i < q_size; i++) {
                TreeNode *curNode = q.front();
                q.pop();

                maxVal = max(maxVal, curNode->val);

                if (curNode->left) {
                    q.push(curNode->left);
                }
                if (curNode->right) {
                    q.push(curNode->right);
                }
            }
            res.push_back(maxVal);
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    vector<int> res = sol.largestValues(root);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}

