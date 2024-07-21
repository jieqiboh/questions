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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // i stops before node to remove
        // j stops after node to remove
        // k stops at end node
        ListNode *end = head;
        ListNode *i_node = head;
        ListNode *k_node = head;
        int num_nodes = 1;
        while (end->next) {
            num_nodes++;
            end = end->next;
        }

        int j_moves = num_nodes - n + 1; // j_moves < num_nodes
        int i_moves = j_moves - 2;
        if (j_moves == num_nodes && i_moves < 0) { // last node and first node same, and to be removed
            return nullptr;
        } else if (j_moves == num_nodes) { // last node to be removed
            for (int i = 0; i < i_moves; i++) {
                i_node = i_node->next;
            }
            i_node->next = nullptr;
            return head;
        } else if (i_moves < 0) { // first node to be removed
            return head->next;
        }

        // good case
        for (int i = 0; i < j_moves; i++) {
            k_node = k_node->next;
        }
        for (int i = 0; i < i_moves; i++) {
            i_node = i_node->next;
        }
        i_node->next = k_node;

        return head;
    }
};

int main() {
    fast();

    return 0;
}

