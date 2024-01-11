#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* cur;
    ListNode* head = new ListNode(-1);
    cur = head;

    while (l1 != nullptr && l2 != nullptr) {
        int sum = l1->val + l2->val + carry;
        carry = (sum >= 10) ? 1 : 0;
        int num = sum % 10;
        ListNode* newNode = new ListNode(num);
        cur->next = newNode;

        newNode = newNode->next;
        cur = cur->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 == nullptr) {
        while (l2 != nullptr) {
            int sum = l2->val + carry;
            carry = (sum >= 10) ? 1 : 0;
            int num = sum % 10;
            ListNode* newNode = new ListNode(num);
            cur->next = newNode;

            newNode = newNode->next;
            cur = cur->next;

            l2 = l2->next;
        }
    } else if (l2 == nullptr) {
        while (l1 != nullptr) {
            int sum = l1->val + carry;
            carry = (sum >= 10) ? 1 : 0;
            int num = sum % 10;
            ListNode* newNode = new ListNode(num);
            cur->next = newNode;

            newNode = newNode->next;
            cur = cur->next;

            l1 = l1->next;
        }
    }

    if (carry == 1) {
        ListNode* newNode = new ListNode(1);
        cur->next = newNode;
    }

    return head->next;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

    cout << endl;
}

int main() {
    // Create l1: [9, 9, 9, 9, 9, 9, 9]
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    // Create l2: [9, 9, 9, 9]
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    // Now, l1 and l2 are created as specified.

    // You can use l1 and l2 as needed.
    ListNode* res = addTwoNumbers(l1, l2);

    printLinkedList(res);
    return 0;
}