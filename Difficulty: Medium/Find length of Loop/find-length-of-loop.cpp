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
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if (fast == NULL || fast->next == NULL) return 0;
        
        int count = 1;
        fast = fast->next;
        while(slow != fast){
            fast = fast->next;
            count++;
        }
        return count;
    }
};