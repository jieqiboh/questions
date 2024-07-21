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
    int kthSmallest(TreeNode *root, int k) {
        vector<int> res;
        traverse(root, res);

        return res[k-1];
    }
    void traverse(TreeNode *root, vector<int>& nums) {
        if (root != nullptr) {
            if (root->left != nullptr) {
                traverse(root->left, nums);
            }
            nums.push_back(root->val);
            if (root->right != nullptr) {
                traverse(root->right, nums);
            }
        }
    }
};

int main() {
    fast();

    Solution sol;


    return 0;
}

