/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int findLength(Node *head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }

    Node* swapKth(Node* head, int k) {
        int len = findLength(head);
        if(k > len) return head;
        if (k == len - k + 1) return head;
        
        Node *start = head, *start_prev = NULL;
        for(int i = 1; i < k; i++) {
            start_prev = start;
            start = start->next;
        }
        
        Node *end = head, *end_prev = NULL;
        for(int i = 1; i < len - k + 1; i++) {
            end_prev = end;
            end = end->next;
        }
        
        if(start_prev) start_prev->next = end;
        if(end_prev) end_prev->next = start;
        
        Node* temp = start->next;
        start->next = end->next;
        end->next = temp;
        
        if(k == 1) head = end;
        if(k == len) head = start;
        
        return head;
    }
};

