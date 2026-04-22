/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* group_prev = dummy;
        while (true) {
            ListNode* kth = get_kth(group_prev, k);
            if (!kth) break;
            ListNode* group_next = kth -> next;
            ListNode* prev = group_next;
            ListNode* cur = group_prev -> next;
            while (cur != group_next) {
                ListNode* temp = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = temp;
            }
            ListNode* temp = group_prev -> next;
            group_prev -> next = kth;
            group_prev = temp;
        }
        return dummy -> next;
    }
private:
    ListNode* get_kth(ListNode* cur, int k) {
        while (cur and k) {
            cur = cur -> next;
            k--;
        }
        return cur;
    }
};
