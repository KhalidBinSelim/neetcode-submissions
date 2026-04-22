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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp;
        ListNode* res = &temp;
        ListNode* fir = list1; ListNode* sec = list2;
        while (fir and sec) {
            if (fir -> val <= sec -> val) {
                res -> next = fir;
                fir = fir -> next;
            } else {
                res -> next = sec;
                sec = sec -> next;
            }
            res = res -> next;
        } 
        if (fir) res -> next = fir;
        else res -> next = sec;
        return temp.next;
    }
};