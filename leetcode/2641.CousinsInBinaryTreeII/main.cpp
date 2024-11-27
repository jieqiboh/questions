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
    TreeNode *replaceValueInTree(TreeNode *root) {
        queue<TreeNode*> q; // cur

        q.push(root);
        int prevLvlSum = root->val;
        while (!q.empty()) {
            int qSz = q.size();
            int curLvlSum = 0;

            for (int i = 0; i < qSz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                cur->val = prevLvlSum - cur->val; // assign val to sum of whole level - sum of own siblings

                int leftVal = (cur->left == nullptr) ? 0 : cur->left->val;
                int rightVal = (cur->right == nullptr) ? 0 : cur->right->val;
                int childrenSum = leftVal + rightVal;

                curLvlSum += childrenSum;

                if (cur->left != nullptr) {
                    cur->left->val = childrenSum; // assign val to sum of siblings
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    cur->right->val = childrenSum;
                    q.push(cur->right);
                }
            }
            prevLvlSum = curLvlSum;
        }
        return root;
    }
};

int main() {
    fast();

    return 0;
}

