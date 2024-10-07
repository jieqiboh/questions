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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Definition for a binary tree node.
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
    bool isSubPath(ListNode *head, TreeNode *root) {
    }

    bool dfs(ListNode *head, ListNode *cur, TreeNode *root) {
        if (cur == nullptr) return true; // end of linked list reached
        if (root == nullptr) return false; // end of tree reached but not LL, so ret false

        if (cur->val == root->val) { // current matches root
            cur = cur->next;
        } else if (head->val == root->val)  { // cur doesnt match, but head does, so try reset dfs
            cur = head;
        } else { // both no match

        }

        return dfs(head, cur, root->left) || dfs(head, cur, root->right);
    }
};

int main() {
    fast();

    return 0;
}

