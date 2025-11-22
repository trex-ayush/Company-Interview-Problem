/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next != head && fast->next->next != head){
            slow=slow->next;
            fast = fast->next->next;
        }
        
        if(fast->next != head){
            fast = fast->next;
        }
        
        Node* headB = slow->next;
        slow->next = head;
        fast->next = headB;
        return { head, headB};
    }
};