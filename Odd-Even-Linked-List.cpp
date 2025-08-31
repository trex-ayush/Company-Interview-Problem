class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even = new ListNode(-1);
        ListNode *odd  = new ListNode(-1);
        ListNode *evenTraversal = even;
        ListNode *oddTraversal  = odd;
        ListNode *temp = head;
        int count = 1;

        while(temp){
            if(count % 2 != 0){
                oddTraversal->next = temp;
                oddTraversal = oddTraversal->next;
            }else{
                evenTraversal->next = temp;
                evenTraversal = evenTraversal->next;
            }
            count++;
            temp = temp->next;
        }
        evenTraversal->next = NULL;
        oddTraversal->next = even->next;
        ListNode *res = odd->next;
        delete odd;
        delete even;
        return res;
    }
};