/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x == 1) return head->next;
        Node* curr = head;
        int count = 1;
        
        while(curr){
            if(count + 1 == x){
                curr->next = curr->next->next;
            }
            count++;
            curr = curr->next;
        }
        return head;
    }
};