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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        
        // split the list in the middle, invoke sortList on the 2 lists, then merge
        ListNode *mid = findMid(head);
        ListNode *lHead = head;
        ListNode *rHead = mid->next;
        mid->next = nullptr;

        lHead = sortList(lHead);
        rHead = sortList(rHead);
        return merge(lHead, rHead);
    }

    ListNode *findMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *h1, ListNode *h2) {
        // given 2 heads, merge and return the head of the merged list
        if (!h1) return h2;
        if (!h2) return h1;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        if (h1->val <= h2->val) {
            head = h1;
            tail = h1;
            h1 = h1->next;
        } else {
            head = h2;
            tail = h2;
            h2 = h2->next;
        }

        while (h1 && h2) {
            if (h1->val <= h2->val) {
                tail->next = h1;
                tail = h1;
                h1 = h1->next;
            } else {
                tail->next = h2;
                tail = h2;
                h2 = h2->next;
            }
        }
        if (!h1) {
            tail->next = h2;
        } else {
            tail->next = h1;
        }
        return head;
    }
};
// Function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    fast();

    Solution sol;
    vector<int> head = {-1, 5, 3, 4, 1};

    // Create the linked list
    ListNode* linkedList = createLinkedList(head);
    printLinkedList(linkedList);

    ListNode *sortedLL = sol.sortList(linkedList);
    printLinkedList(sortedLL);

    // First sorted list
    vector<int> list1 = {1, 4, 5, 6, 7};
    ListNode* sortedList1 = createLinkedList(list1);

    // Second sorted list
    vector<int> list2 = {1, 2, 3, 11, 13};
    ListNode* sortedList2 = createLinkedList(list2);
    ListNode *res = sol.merge(sortedList1, sortedList2);

    printLinkedList(res);

    vector<int> list3 = {17};
    ListNode* sortedList3 = createLinkedList(list3);

    vector<int> list4 = {};
    ListNode* sortedList4 = createLinkedList(list4);
    ListNode *res2 = sol.merge(sortedList3, sortedList4);

    printLinkedList(res2);

    return 0;
}

