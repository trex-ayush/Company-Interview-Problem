/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(!head || k == 1) return head;
        
        Node *curr = head;
        Node *prev = NULL;
        Node *forw;
        int count = 0;
        
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