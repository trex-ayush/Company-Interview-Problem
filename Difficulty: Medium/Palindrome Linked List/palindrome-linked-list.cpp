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
    Node *reverse(Node *head){
        Node *curr = head;
        Node *prev = NULL;
        
        while(curr){
            Node* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;
        
        Node *slow = head;
        Node *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node *rev = reverse(slow);
        
        Node *temp = head;
        while(rev){
            if(temp->data != rev->data) return false;
            temp = temp->next;
            rev = rev->next;
        }
        return true;
    }
};