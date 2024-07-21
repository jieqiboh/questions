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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res(0);
        if (root == nullptr) return res;
        queue<TreeNode*> q;

        q.push(root);
        int cur_size = 1;
        while (!q.empty()) {
            int new_size = 0;
            vector<int> level;
            for (int i = 0; i < cur_size; i++) {
                TreeNode* node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                    new_size++;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    new_size++;
                }
            }
            res.push_back(level);
            cur_size = new_size;
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}

