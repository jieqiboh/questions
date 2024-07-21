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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) return false;

            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
        
    }
};

int main() {
    fast();

    Solution sol;

        // Initialize nodes
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // Link nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Create cycle here

    // Check if the linked list has a cycle
    bool result = sol.hasCycle(node1);
    std::cout << "Has cycle: " << (result ? "Yes" : "No") << "\n";

    return 0;
}

