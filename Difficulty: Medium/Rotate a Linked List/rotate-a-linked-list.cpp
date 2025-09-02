/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getLength(Node* head){
        int cnt = 0;
        Node *temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    Node* rotate(Node* head, int k) {
        if(!head || !head->next || k == 0) return head;
        
        int len = getLength(head);
        k = k % len;
        if (k == 0) return head;
        
        k = len - k;    // convert right rotation to left rotation
        if (k == len) return head;
        
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        
        Node* temp = head;
        for(int i = 0; i < len - k - 1; i++){
            temp = temp->next;
        }
        
        k = len - k;
        Node *res = temp->next;
        temp->next = NULL;
        return res;
    }
};