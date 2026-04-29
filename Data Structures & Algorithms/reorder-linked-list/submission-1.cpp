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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast and fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* second = slow -> next;
        ListNode* prev = slow -> next = nullptr;
        while (second) {
            ListNode* front = second -> next;
            second -> next = prev;
            prev = second;
            second = front;
        }
        ListNode* first = head;
        second = prev;
        while (second) {
            ListNode* cur1 = first -> next;
            ListNode* cur2 = second -> next;
            first -> next = second;
            second -> next = cur1;
            first = cur1;
            second = cur2;
        }
    }
};