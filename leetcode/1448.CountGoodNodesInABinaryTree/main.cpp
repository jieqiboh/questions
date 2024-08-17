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
    int goodNodes(TreeNode *root) {
        int res = 0;
        int curMax = INT32_MIN;
        dfs(root, curMax, res);
        return res;
    }
    
    void dfs(TreeNode *root, int curMax, int& res) {
        if (root->val >= curMax) {
            curMax = root->val;
            res++;
        }
        if (root->left) {
            dfs(root->left, curMax, res);
        }

        if (root->right) {
            dfs(root->right, curMax, res);
        }
    }
};

int main() {
    fast();

    return 0;
}

