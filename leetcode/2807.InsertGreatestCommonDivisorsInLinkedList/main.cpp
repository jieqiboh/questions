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
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        if (!head->next) return head;

        ListNode *cur = head;
        ListNode *nxt = head->next;

        while (nxt) {
            int gcdNode = gcd(cur->val, nxt->val);
            ListNode *mid = new ListNode(gcdNode);
            cur->next = mid;
            mid->next = nxt;
            nxt = nxt->next;
        }
        return head;
    }
    int gcd(int a, int b) {
        // Everything divides 0
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        // base case
        if (a == b)
            return a;

        // a is greater
        if (a > b)
            return gcd(a - b, b);
        return gcd(a, b - a);
    }
};

int main() {
    fast();

    return 0;
}

