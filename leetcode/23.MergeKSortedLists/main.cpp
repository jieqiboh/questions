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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            vector<ListNode*> tmp;
            for (int i = 0; i < lists.size(); i+=2) {
                ListNode *l1 = lists[i];
                ListNode *l2 = (i+1 < lists.size()) ? lists[i+1] : nullptr;
                tmp.push_back(mergeLists(l1, l2));
            }
            lists = tmp;
        }
        return lists[0];
    }
    ListNode *mergeLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (!l1) {
            cur->next = l2;
        } else if (!l2) {
            cur->next = l1;
        }
        return dummy->next;
    }
};

int main() {
    fast();

    return 0;
}

