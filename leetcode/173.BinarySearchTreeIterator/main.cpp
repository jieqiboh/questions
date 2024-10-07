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

class BSTIterator {
private:
    void traverse(vector<int>& values, TreeNode *root) {
        // does an inorder traversal of root and appends value to values
        if (root == nullptr) return;
        traverse(values, root->left);
        values.push_back(root->val);
        traverse(values, root->right);
    }
public:
    vector<int> values;
    int i;
    BSTIterator(TreeNode *root) {
        this->values = {};
        this->i = -1; // current idx
        traverse(values, root);
    }

    int next() {
        this->i++;
        return values[i];
    }

    bool hasNext() {
        return i < values.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    fast();

    return 0;
}

