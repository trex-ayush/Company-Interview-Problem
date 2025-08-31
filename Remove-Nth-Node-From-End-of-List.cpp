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

// Company tags: Adobe, Amazon, Apple, Bloomberg, Capgemini, Meta, Microsoft, Nvidia, PayPal, Tinkoff, Uber, Yahoo
class Solution {
public:
    // Time complexity  : O(l)
    // Space complexity : O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first  = head;
        ListNode* second = head;

        for(int i = 0; i < n; i++){
            first = first->next;
        }

        if(first == NULL){
            return head->next;
        }

        while(first && first->next){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return head;
    }
};