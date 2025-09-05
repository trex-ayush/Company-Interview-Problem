/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zeroStart = new Node(-1);
        Node* oneStart = new Node(-1);
        Node* twoStart = new Node(-1);
        
        Node *zeroNext = zeroStart;
        Node *oneNext  = oneStart;
        Node *twoNext  = twoStart;
        Node *node = head;
        
        while(node){
            if(node->data==0){
                zeroNext->next=node;
                zeroNext=node;
            }else if(node->data==1){
                oneNext->next=node;
                oneNext=node;
            }else{
                twoNext->next=node;
                twoNext=node;
            }
            node=node->next;
        }
        
        twoNext->next = NULL;
        oneNext->next=twoStart->next;
        zeroNext->next=oneStart->next;
        
        return zeroStart->next;
    }
};