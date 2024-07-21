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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        int listSize = 0;
        ListNode *cur = head;
        vector<ListNode*> nodes(0);
        while (cur != nullptr) {
            listSize++;
            nodes.push_back(cur);
            cur = cur->next;
        }
        int actNumRot = listSize > 0 ? k % listSize : 0;
        if (actNumRot > 0) {
            ListNode* newHead = nodes[listSize - actNumRot];
            ListNode* newTail = nodes[listSize - actNumRot - 1];
            ListNode* prevTail = nodes[listSize - 1];
            newTail->next = nullptr;
            prevTail->next = head;
            return newHead;
        } else {
            return head;
        }
    }
};

int main() {
    fast();

    return 0;
}

