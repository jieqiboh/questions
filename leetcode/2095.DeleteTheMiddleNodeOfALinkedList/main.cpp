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
    ListNode *deleteMiddle(ListNode *head) {
        if (head->next == nullptr) {
            return nullptr;
        } else if (head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }

        ListNode *end = head;
        int nn = 0; // size of linked list
        while (end) {
            nn++;
            end = end->next;
        }

        ListNode *i_node = head;
        ListNode *j_node = head;
        int i_moves = (nn / 2) - 1;
        int j_moves = (nn / 2) + 1;

        for (int i = 0; i < i_moves; i++) {
            i_node = i_node->next;
        }
        for (int i = 0; i < j_moves; i++) {
            j_node = j_node->next;
        }
        i_node->next = j_node;
        return head;
    }
};

int main() {
    fast();
    // Create the nodes
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);


    Solution sol;
    sol.deleteMiddle(node1);

    // Print the linked list
    ListNode* current = node1;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    // Clean up memory
    current = node1;
    ListNode* temp;
    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

