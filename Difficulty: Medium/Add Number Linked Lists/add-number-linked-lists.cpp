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
    Node* reverse(struct Node* &head){
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr!=NULL){
            Node* forward = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        //Step 1: reverse both LL
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        //Step 2: add LL
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;
        
        while(head1!=NULL || head2!=NULL || carry){
            int sum = carry;
            if(head1){
                sum += head1->data;
                head1 = head1->next;
            }
            if(head2){
                sum += head2->data;
                head2 = head2->next;
            }
            
            int digit = sum % 10;
            carry = sum / 10;
            
            Node* newNode = new Node(digit);
            
            if(ansHead == NULL){
                ansHead = newNode;
                ansTail = newNode;
            }else{
                ansTail->next = newNode;
                ansTail = newNode;
            }
        }
        
        //Step 3: reverse added LL
        ansHead = reverse(ansHead);
        Node* temp = ansHead;
        while(temp->next != NULL && temp->data == 0) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        ansHead = temp;
        
        return ansHead;
    }
};