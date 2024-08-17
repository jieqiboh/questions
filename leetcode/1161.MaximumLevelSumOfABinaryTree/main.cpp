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
    int maxLevelSum(TreeNode *root) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(root);
        visited.insert(root);
        int levelNo = 1;
        int maxLevel = 1;
        int frontierSize = 1; // size of the current frontier
        int nextFrontierSize = 0;
        int maxVal = INT32_MIN;
        int curVal = 0;

        while (!q.empty()) {
            TreeNode *curNode = q.front();
            q.pop();

            // do addition
            curVal += curNode->val;

            // push nodes for next frontier
            if (curNode->left) {
                q.push(curNode->left);
                nextFrontierSize++;
            }
            if (curNode->right) {
                q.push(curNode->right);
                nextFrontierSize++;
            }

            // deduct from frontierSize
            frontierSize--;
            if (frontierSize == 0) {
                if (curVal > maxVal) {
                    maxLevel = levelNo;
                    maxVal = curVal;
                }
                frontierSize = nextFrontierSize;
                nextFrontierSize = 0;
                levelNo++;
                curVal = 0;
            }
        }
        return maxLevel;
    }
};

int main() {
    fast();
    // Create nodes
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(7);
    TreeNode* node3 = new TreeNode(0);
    TreeNode* node4 = new TreeNode(7);
    TreeNode* node5 = new TreeNode(-8);

    // Link nodes to form the tree
    node1->left = node2;  // 1's left child is 7
    node1->right = node3; // 1's right child is 0
    node2->left = node4;  // 7's left child is 7
    node2->right = node5; // 7's right child is -8

    Solution sol;
    cout << sol.maxLevelSum(node1) << "\n"; // 2

    // Create nodes
    node1 = new TreeNode(-100);
    node2 = new TreeNode(-200);
    node3 = new TreeNode(-300);
    node4 = new TreeNode(-20);
    node5 = new TreeNode(-5);
    TreeNode *node6 = new TreeNode(-10);

    // Link nodes to form the tree
    node1->left = node2;  // -100's left child is -200
    node1->right = node3; // -100's right child is -300
    node2->left = node4;  // -200's left child is -20
    node2->right = node5; // -200's right child is -5
    node3->left = node6;  // -300's left child is -10

    cout << sol.maxLevelSum(node1) << "\n"; // 2

    return 0;
}

