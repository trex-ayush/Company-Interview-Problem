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
 // Company tags: Roblox, BNY Mellon, Infosys
class Solution {
public:
    // Time Complexity : O(n)
    // Space Complexity: O(1) 
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* temp = head;
        while(temp){
            result = result * 2 + temp->val;
            temp = temp->next;
        }
        return result;
    }
};