// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        if(!head || !head->next) return head;
        
        Node *even = new Node(-1);
        Node *odd  = new Node(-1);
        Node *evenTraversal = even;
        Node *oddTraversal  = odd;
        Node *temp = head;
        
        while(temp){
            if(temp->data % 2 != 0){
                oddTraversal->next = temp;
                oddTraversal = oddTraversal->next;
            }else{
                evenTraversal->next = temp;
                evenTraversal = evenTraversal->next;
            }
            temp = temp->next;
        }
        oddTraversal->next = NULL;
        evenTraversal->next = odd->next;
        
        return even->next;
    }
};