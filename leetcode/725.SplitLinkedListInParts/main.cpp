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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int tmpk = k;
        vector<ListNode*> res;
        ListNode *cur = head;
        int remSize = 0;
        while (cur) {
            remSize++;
            cur = cur->next;
        }
        cur = head;

        while (remSize > 0) {
            int curSize = ceil((double)remSize / (double)k);
            ListNode *newHead = cur; // points to last node of cur LL
            ListNode *tmp = cur;
            for (int i = 0; i < curSize - 1; i++) {
                newHead = newHead->next;
            }
            cur = newHead->next;
            newHead->next = nullptr;
            res.push_back(tmp);
            remSize -= curSize;
            k--;
        }
        int resSize = res.size();
        for (int i = 0; i < (int)(tmpk - resSize); i++) {
            res.push_back({});
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    // Manually constructing the linked list [1,2,3,4,5,6,7,8,9,10]
//    ListNode* node10 = new ListNode(10);
//    ListNode* node9 = new ListNode(9, node10);
//    ListNode* node8 = new ListNode(8, node9);
//    ListNode* node7 = new ListNode(7, node8);
//    ListNode* node6 = new ListNode(6, node7);
//    ListNode* node5 = new ListNode(5, node6);
//    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);  // This is the head of the list
    vector<ListNode *> res = sol.splitListToParts(head, 5);

    return 0;
}

