// Company tags: Adobe, Amazon, Apple, Bloomberg, Infosys, LinkedIn, Meta, Microsoft, Morgan Stanley, Oracle, Siemens, Yahoo
class Solution {
public:
    // Time Complexity : O(n)
    // Space Complexity: O(1)
    int getLength(ListNode* head){
        int cnt = 0;
        ListNode *temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int len = getLength(head);
        k = k % len;
        if (k == 0) return head;

        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;

        ListNode* temp = head;
        for(int i = 0; i < len - k - 1; i++){
            temp = temp->next;
        }
        ListNode *res = temp->next;
        temp->next = NULL;
        return res;
    }
};