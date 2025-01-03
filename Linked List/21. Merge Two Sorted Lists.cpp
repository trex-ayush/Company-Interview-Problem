/*
Problem Name: Leetcode 21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/description/

Asked by : Microsoft

Time Complexity : O(l1 + l2) where l1 & l2 are lengths of lists
Space Complexity : O(1)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                ans->next = temp1;
                temp1 = temp1->next;
                ans = ans->next;
            }else{
                ans->next = temp2;
                temp2 = temp2->next;
                ans = ans->next;
            }
        }
        while(temp1){
            ans->next = temp1;
            temp1 = temp1->next;
            ans = ans->next;
        }
        while(temp2){
            ans->next = temp2;
            temp2 = temp2->next;
            ans = ans->next;
        }
        return dummy->next;
    }
};