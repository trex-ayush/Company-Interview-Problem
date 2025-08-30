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

// Company tags: Walmart Labs, Qualcomm, Intuit, Zoho, Snap
class Solution {
public:
    // Time complexity  : O(n)
    // Space complexity : O(1)
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};