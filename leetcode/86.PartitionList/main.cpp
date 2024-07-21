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
    ListNode *partition(ListNode *head, int x) {
        ListNode *leftHead = nullptr; // contains LT
        ListNode *leftTail = nullptr; // contains LT
        ListNode *rightHead = nullptr; // contains GTE 
        ListNode *rightTail = nullptr; // contains GTE 

        ListNode *cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                if (leftHead == nullptr) {
                    leftHead = cur;
                    leftTail = leftHead;
                } else {
                    leftTail->next = cur;
                    leftTail = leftTail->next;
                }
            } else {
                if (rightHead == nullptr) {
                    rightHead = cur;
                    rightTail = rightHead;
                } else {
                    rightTail->next = cur;
                    rightTail = rightTail->next;
                }
            }
            cur = cur->next;
        }
        leftTail->next = rightHead;
        rightTail->next = nullptr;

        return leftHead;
    }
};

int main() {
    fast();

    // Manually creating the linked list [1, 4, 3, 2, 5, 2]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    Solution sol;
    head = sol.partition(head, 3);

    // Print the linked list to verify
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    // Clean up the memory to prevent memory leaks
//    current = head;
//    while (current != nullptr) {
//        ListNode* next = current->next;
//        delete current;
//        current = next;
//    }

    return 0;
}

