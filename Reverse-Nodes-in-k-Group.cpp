// Company tags: Adobe, Amazon, Apple, Arista Networks, Autodesk, Bloomberg, Capital One, Commvault, DE Shaw, Infosys, Josh Technology, MakeMyTrip, MathWorks, Meta, Microsoft, Nutanix, Qualcomm, Snowflake, Tesla, TikTok, Uber, Visa, VMware, Walmart Labs, Yahoo, Zeta, Zomato
class Solution {
public:
    /*
    Time & Space Complexity:
        Time: O(n) — Each node is visited once.
        Space: O(n/k) recursive calls (due to recursion stack).
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        int count = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            count++;
            if(count > k) break;
        }
        if(count < k) return head;
        count = 0;

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *forw;
        while(curr && count < k){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;
        }
        
        if(forw){
            head->next = reverseKGroup(forw, k);
        }
        
        return prev;
    }
};