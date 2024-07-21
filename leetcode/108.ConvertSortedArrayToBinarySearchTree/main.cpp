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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return tree(nums, 0, nums.size() - 1);
    }

    TreeNode *tree(vector<int> &nums, int l, int r) {
        // given the indexes [l, r] of nums, construct the BST of that range and return root node
        if (l == r) {
            return new TreeNode(nums[l]);
        } else if (l > r) {
            return nullptr;
        } else {
            int mid = l + (r - l) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->right = tree(nums, mid + 1, r);
            root->left = tree(nums, l, mid - 1);
            return root;
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> nums = {-10,-3,0,5,9};
    sol.sortedArrayToBST(nums);

    return 0;
}

