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
         long long n1 = 0;
         long long n2 = 0;

        ListNode *node1 = l1;
        while (node1) {
            n1 *= 10;
            n1 += node1->val;
            node1 = node1->next;
        }
        ListNode *node2 = l2;
        while (node2) {
            n2 *= 10;
            n2 += node2->val;
            node2 = node2->next;
        }

         long long res = n1 + n2;
        string resStr = to_string(res);

        ListNode *resNode = arrayToList(resStr);
        return resNode;
    }
    // Function to insert node
    void insert(ListNode** root,  long long item) {
        ListNode* temp = new ListNode(item);
        temp->next = *root;
        *root = temp;
    }

    ListNode *arrayToList(string s) {
        ListNode *root = NULL;
        for (int i = s.size()-1; i >= 0 ; i--)
            insert(&root, s[i] - '0');
        return root;
    }
};

int main() {
    fast();
    Solution sol;

    // Linked list l1 = [7, 2, 4, 3]
    ListNode* l1_3 = new ListNode(3);
    ListNode* l1_2 = new ListNode(4, l1_3);
    ListNode* l1_1 = new ListNode(2, l1_2);
    ListNode* l1 = new ListNode(7, l1_1);

// Linked list l2 = [5, 6, 4]
    ListNode* l2_3 = new ListNode(4);
    ListNode* l2_2 = new ListNode(6, l2_3);
    ListNode* l2 = new ListNode(5, l2_2);

    ListNode *res = sol.addTwoNumbers(l1, l2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}

