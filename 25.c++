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
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* tail = head;
        for(int i=0; i<k; i++){
            if(tail == nullptr){
                return head;
            }
            tail = tail->next;
        }
        ListNode* newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }
    ListNode* reverse(ListNode* cur, ListNode* tail){
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while(cur != tail){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};