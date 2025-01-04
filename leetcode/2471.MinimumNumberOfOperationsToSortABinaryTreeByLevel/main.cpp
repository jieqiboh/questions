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
    int minimumOperations(TreeNode *root) {
        int swaps = 0;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int qSize = q.size();
            vector<int> lvl;

            for (int i = 0; i < qSize; i++) {
                TreeNode *cur = q.front();
                q.pop();

                lvl.push_back(cur->val);

                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            swaps += getMinSwaps(lvl);

            lvl.clear();
        }
        return swaps;
    }
    int getMinSwaps(vector<int>& arr) {
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());

        // Map to track current positions of values
        unordered_map<int, int> pos;
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != sortedArr[i]) {
                swaps++;

                int curPos = pos[sortedArr[i]]; // current pos of element supposed to be in this idx
                pos[arr[i]] = curPos;
                swap(arr[curPos], arr[i]);
            }
        }
        return swaps;
    }
};

int main() {
    fast();

    return 0;
}

