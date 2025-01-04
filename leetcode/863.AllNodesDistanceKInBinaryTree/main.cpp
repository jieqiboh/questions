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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        dfs(root, graph); // initialise graph

        set<int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target->val);

        while (!q.empty() && k) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode *cur = q.front();
                visited.insert(cur->val);
                q.pop();

                for (TreeNode *nbr : graph[cur]) {
                    if (visited.find(nbr->val) == visited.end()) {
                        q.push(nbr);
                    }
                }
            }
            k--;
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
    void dfs(TreeNode *root, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (root->left != nullptr) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            dfs(root->left, graph);
        }
        if (root->right != nullptr) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            dfs(root->right, graph);
        }
    }
};

int main() {
    fast();
    Solution sol;
    // Level 4
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    // Level 3
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2, node7, node4);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);

    // Level 2
    TreeNode* node5 = new TreeNode(5, node6, node2);
    TreeNode* node1 = new TreeNode(1, node0, node8);

    // Level 1 (Root)
    TreeNode* root = new TreeNode(3, node5, node1);
    vector<int> res = sol.distanceK(root, node5, 2);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

