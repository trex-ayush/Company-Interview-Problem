class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        
        while(curr){
            ListNode *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *rev = reverse(slow);
        
        ListNode *temp = head;
        while(rev){
            if(temp->val != rev->val) return false;
            temp = temp->next;
            rev = rev->next;
        }
        return true;
    }
};