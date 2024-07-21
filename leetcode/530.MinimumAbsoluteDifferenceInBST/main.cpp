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
    int getMinimumDifference(TreeNode *root) {
        set<int> nums;
        traverse(root, nums);
        vector<int> v(nums.begin(), nums.end());

        int min_diff = INT32_MAX;
        for (int i = 0; i < v.size() - 1; i++) {
            min_diff = min(min_diff, v[i+1] - v[i]);
        }
        return min_diff;
    }
    void traverse(TreeNode *root, set<int>& nums) {
        if (root != nullptr) {
            nums.insert(root->val);
            traverse(root->right, nums);
            traverse(root->left, nums);
        }
    }
};

int main() {
    fast();

    return 0;
}

