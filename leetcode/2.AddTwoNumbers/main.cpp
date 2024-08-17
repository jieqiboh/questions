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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0, nullptr);
        ListNode *cur = dummy;

        int carry = 0;
        while (l1 || l2) {
            ListNode *tmp;
            int n1 = (l1 != nullptr) ? l1->val : 0;
            int n2 = (l2 != nullptr) ? l2->val : 0;

            int numSum = n1 + n2 + carry;
            if (numSum >= 10) {
                tmp = new ListNode(numSum % 10, nullptr);
                cur->next = tmp;
                cur = tmp;
                carry = 1;
            } else {
                tmp = new ListNode(numSum, nullptr);
                cur->next = tmp;
                cur = tmp;
                carry = 0;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry == 1) {
            cur->next = new ListNode(1, nullptr);
        }
        return dummy->next;
    }
};

int main() {
    fast();

    return 0;
}

