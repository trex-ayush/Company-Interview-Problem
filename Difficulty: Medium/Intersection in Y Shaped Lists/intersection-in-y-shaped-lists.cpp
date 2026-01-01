/*
class Node {
public:
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
    Node* intersectPoint(Node* head1, Node* head2) {
        Node *cur1 = head1;
        Node *cur2 = head2;
        while(cur1 && cur2){
            if(cur1 == cur2) return cur1;
            
            cur1 = cur1->next;
            cur2 = cur2->next;
            
            if(cur1 == NULL) cur1 = head2;
            if(cur2 == NULL) cur2 = head1;
        }
    }
};