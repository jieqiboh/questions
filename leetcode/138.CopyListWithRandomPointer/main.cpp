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

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head || !head->next) {
            Node* res = head;
            return res;
        }
        unordered_map<int,int> randoms; // maps vals to their randoms val
        vector<int> values; // stores the order of the vals and their nexts val

        int head_val = head->val;
        Node* cur = head; // used to traverse the original list

        while (cur != NULL) {
            if (cur->random) {
                randoms.insert(make_pair(cur->val,cur->random->val));
                values.push_back(cur->val);
                cout << "Cur val: " << cur->val << " , Cur random: " << cur->random->val << "\n";
            } else {
                values.push_back(cur->val);
                cout << "Cur val: " << cur->val << " , Cur random: " << "null" << "\n";
            }
            cur = cur->next;
        }
        cur = head; // reassign back to head

        Node* res_head = new Node(values[0]);
        if (randoms.find(res_head->val) != randoms.end()) {
            res_head->random = randoms[res_head->val];
        }
        Node* res_cur = res_head;

        for (int i = 0; i < values.size(); i++) {

        }
//        while (res_cur != NULL) {
//            int next_val;
//            int next_random;
//            Node* new_node;
//            if (values.find(res_cur->val) != values.end()) { // res_cur is not the last node
//                next_val = values[res_cur->val];
//                new_node = new Node(next_val);
//            }
//            if (randoms.find(res_cur->random->val) != randoms.end())
//        }
        return nullptr;

    }
};

int main() {
    fast();
    // Step 1: Create the nodes
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    // Step 2: Link the 'next' pointers
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    // Step 3: Link the 'random' pointers
    node1->random = NULL;        // 7 -> null
    node2->random = node1;       // 13 -> 7
    node3->random = node5;       // 11 -> 1
    node4->random = node3;       // 10 -> 11
    node5->random = node1;       // 1 -> 7

    Solution sol;
    sol.copyRandomList(node1);

    // For testing purposes, let's print the list
//    Node* head = node1;
//    while (head != NULL) {
//        cout << "Node value: " << head->val << ", Random value: ";
//        if (head->random)
//            cout << head->random->val;
//        else
//            cout << "null";
//        cout << "\n";
//        head = head->next;
//    }

    return 0;
}

