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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    vector<int> split(const string &str, char delim) {
        vector<int> tokens;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delim)) {
            if (!token.empty())
                tokens.push_back(stoi(token));
        }
        return tokens;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<int> splitData = split(data, ',');
        if (splitData.empty()) return nullptr;
        stack<TreeNode*> upBounds;
        upBounds.push(new TreeNode(INT32_MAX));
        TreeNode *root = new TreeNode(splitData[0]);
        TreeNode *dummy = root;
        dummy->left = nullptr; dummy->right = nullptr;
        for (int i = 1; i < splitData.size(); i++) {
            int cur = splitData[i];
            if (cur < root->val) {
                root->left = new TreeNode(cur);
                upBounds.push(root);
                root = root->left;
            } else if (cur > root->val) {
                root->left = nullptr;
                while (upBounds.top()->val < cur) {
                    root->right = nullptr;
                    root = upBounds.top();
                    upBounds.pop();
                }
                root->right = new TreeNode(cur);
                root = root->right;
            }
        }
        root->left = nullptr; root->right = nullptr;
        return dummy;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main() {
    fast();

    TreeNode* root = new TreeNode(2);  // Root node with value 2
    root->left = new TreeNode(1);      // Left child with value 1
    root->right = new TreeNode(3);     // Right child with value 3

    // Your Codec object will be instantiated and called as such:
    Codec* ser = new Codec();
    Codec* deser = new Codec();
    string tree = ser->serialize(root);
    TreeNode* ans = deser->deserialize(tree);

    // Next testcase
    root = new TreeNode(10);  // Root node with value 10
    root->left = new TreeNode(7);       // Left child of root with value 7
    root->left->left = new TreeNode(5); // Left child of 7 with value 5
    root->left->right = new TreeNode(8); // Right child of 7 with value 8
    root->left->left->left = new TreeNode(1); // Left child of 5 with value 1

    ser = new Codec();
    deser = new Codec();
    tree = ser->serialize(root);
    ans = deser->deserialize(tree);
    return 0;
}

