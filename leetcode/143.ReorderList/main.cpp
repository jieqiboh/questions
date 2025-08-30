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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        vector<ListNode*> v;
        ListNode* tmp = head;

        while (tmp != nullptr) {
            v.push_back(tmp);
            tmp = tmp->next;
        }
        int l = 0;
        int r = v.size() - 1;

        bool x = true;
        while (l != r) {
            if (x) {
                v[l]->next = v[r];
                l++;
                x = false;
            } else {
                v[r]->next = v[l];
                r--;
                x = true;
            }
        }
        v[l]->next = nullptr;
    }
};

int main() {
    fast();

    return 0;
}

