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
    ListNode *reverseList(ListNode *head) {
        ListNode *i_node = head;
        ListNode *j_node = head;
        ListNode *k_node = head;

        if (head == nullptr) return nullptr; // no nodes

        j_node = j_node->next;
        if (j_node == nullptr) return head; // only 1 node

        k_node = j_node->next;
        if (k_node == nullptr) { // only 2 nodes
            j_node->next = i_node;
            i_node->next = nullptr;
            return j_node;
        }

        i_node->next = nullptr;
        while (k_node) {
            j_node->next = i_node;
            i_node = j_node;
            j_node = k_node;
            k_node = k_node->next;
        }
        j_node->next = i_node;
        return j_node;
    }
};

int main() {
    fast();

    return 0;
}

