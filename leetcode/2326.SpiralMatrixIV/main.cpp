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

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<char> dirs = {'r','d','l','t'}; // right down left top
        int i = 0;
        int k = 0; // row
        int l = 0; // col

        while (m > 0 && n > 0) {
            char dir = dirs[i % 4];
            if (dir == 'r') {
                for (int i = 0; i < n; i++) {
                    int val = (head == nullptr) ? -1 : head->val;
                    res[k][l] = val;
                    l++;
                    if (head != nullptr) head = head->next;
                }
                k++; l--;
                m--;
            } else if (dir == 'd') {
                for (int i = 0; i < m; i++) {
                    int val = (head == nullptr) ? -1 : head->val;
                    res[k][l] = val;
                    k++;
                    if (head != nullptr) head = head->next;
                }
                l--; k--;
                n--;
            } else if (dir == 'l') {
                for (int i = 0; i < n; i++) {
                    int val = (head == nullptr) ? -1 : head->val;
                    res[k][l] = val;
                    l--;
                    if (head != nullptr) head = head->next;
                }
                k--; l++;
                m--;
            } else if (dir == 't') {
                for (int i = 0; i < m; i++) {
                    int val = (head == nullptr) ? -1 : head->val;
                    res[k][l] = val;
                    k--;
                    if (head != nullptr) head = head->next;
                }
                l++; k++;
                n--;
            }
            i++; // change direction
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    // Manually constructing the linked list
    ListNode* head = new ListNode(3);   // Create the head node
    ListNode* node1 = new ListNode(0);  // Second node
    ListNode* node2 = new ListNode(2);  // Third node
    ListNode* node3 = new ListNode(6);  // Fourth node
    ListNode* node4 = new ListNode(8);  // Fifth node
    ListNode* node5 = new ListNode(1);  // Sixth node
    ListNode* node6 = new ListNode(7);  // Seventh node
    ListNode* node7 = new ListNode(9);  // Eighth node
    ListNode* node8 = new ListNode(4);  // Ninth node
    ListNode* node9 = new ListNode(2);  // Tenth node
    ListNode* node10 = new ListNode(5); // Eleventh node
    ListNode* node11 = new ListNode(5); // Twelfth node
    ListNode* node12 = new ListNode(0); // Thirteenth node

    // Manually linking the nodes
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node11;
    node11->next = node12;
    node12->next = nullptr;  // Last node points to nullptr

    sol.spiralMatrix(3, 5, head);


    return 0;
}

