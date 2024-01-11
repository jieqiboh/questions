

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *head = new ListNode(-1);
            ListNode *cur;
            cur = head;

            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    cur->next = list1;
                    list1 = list1->next;
                } else {
                    cur->next = list2;
                    list2 = list2->next;
                }
                cur = cur->next;
            }

            if (list1 == nullptr) {
                cur->next = list2;
            } else if (list2 == nullptr) {
                cur->next = list1;
            }
            return head->next;
        
        }

};