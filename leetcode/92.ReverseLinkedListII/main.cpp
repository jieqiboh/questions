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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);

        // leftPrev is the node directly before left
        // left is the node at left pos
        // we always end up assigning leftPrev.next = right at the end of the reversal
        ListNode *lPrev = dummy;
        ListNode *l = head;
        for (int i = 0; i < left - 1; i++) {
            lPrev = l;
            l = l->next;
        }

        // reverse the section
        ListNode *prev = nullptr;
        ListNode *cur = l;
        for (int i = 0; i < right - left + 1; i++) { // we want cur to point to the node after right
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        l->next = cur;
        lPrev->next = prev;

        return dummy->next;
    }
};

int main() {
    fast();

    return 0;
}

