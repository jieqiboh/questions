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

#define ll long long

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
    ListNode *sortLinkedList(ListNode *head) {
        ListNode* x =  head; // x points to the first at all times
        ListNode* y = x;
        ListNode* z = y->next;

        while (z != nullptr) {
            if (z->val < 0) {
                y->next = z->next;
                z->next = x;
                x = z;
                z = y->next;
            } else {
                y->next = z;
                z = z->next;
            }
        }
    }
};

int main() {
    fast();

    return 0;
}

