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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr || head->next->next == nullptr) {
            return head;
        }

        int nn = 0;
        ListNode *i_node = head;
        ListNode *j_node = i_node->next;
        ListNode *k_node = j_node->next;
        ListNode *second_node = head->next; // maintain pointer for reconnection

        while (k_node) {
            nn++;
            i_node->next = k_node;
            i_node = j_node;
            j_node = k_node;
            k_node = k_node->next;
        }
        if (nn % 2 == 0) {
            i_node->next = second_node;
        } else {
            i_node->next = nullptr;
            j_node->next = second_node;
        }
        return head;
    }
};

int main() {
    fast();

    return 0;
}

