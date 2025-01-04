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
    vector<TreeNode *> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> memo;

        if (n % 2 == 1) return {};

        if (n == 1) return {new TreeNode()};

        vector<TreeNode *> res;

        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode *root = new TreeNode(0, l, r);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    // Level 4
    TreeNode* node7 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(0);

    // Level 3
    TreeNode* node5 = new TreeNode(0, node7, node8);
    TreeNode* node6 = new TreeNode(0);

    // Level 2
    TreeNode* node3 = new TreeNode(0, node5, node6);
    TreeNode* node4 = new TreeNode(0);

    // Level 1 (Root)
    TreeNode* root = new TreeNode(0, node4, node3);
    cout << sol.treeEncoding(root) << "\n";



    return 0;
}

