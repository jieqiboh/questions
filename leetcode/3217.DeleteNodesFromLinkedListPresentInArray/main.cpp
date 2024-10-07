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
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        set<int> s_nums(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(0);
        ListNode *cur = head;
        ListNode *prev = dummy;

        while (cur != nullptr) {
            if (s_nums.find(cur->val) == s_nums.end()) { // valid node found
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }
        prev->next = cur;

        return dummy->next;
    }
};

int main() {
    fast();

    return 0;
}

